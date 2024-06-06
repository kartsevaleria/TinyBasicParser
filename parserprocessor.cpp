#include "parserprocessor.h"

#include <QDebug>

#include "BasicParser.h"
#include "BasicScanner.h"
#include <memory>

extern VirtualBaseNode* root;

YYBufferGuard::YYBufferGuard(YY_BUFFER_STATE* state) :
    mState(state)
{
}

YYBufferGuard::~YYBufferGuard() {
    yy_delete_buffer(*mState);
}


ParserProcessor::ParserProcessor(QByteArray data) : data(data)
{
    numReturn = new std::vector<int>();
    numLinkGoSub = new std::vector<int>();
    numReturn = new std::vector<int>();
}

void ParserProcessor::SetData(QByteArray d)
{
    data = d;
}


int ParserProcessor::BisonParser()
{
    YY_BUFFER_STATE buffer = yy_scan_string(data.constData());
    YYBufferGuard guard(&buffer);
    Q_UNUSED(guard)
    int retcode;
    try {
        retcode = yyparse();
    } catch(ParserException& e) {
        emit ErrorToProtocol(QString("Parse error near line %1: %2").arg(e.lineNumber).arg(e.what).toUtf8().constData());
        retcode = 1;
    }
    return retcode;
}

//+ проверка, что gosub ссылается на существующую строку
void ParserProcessor::SemanticAnalys()
{
    //Как хранить номера строк?
    SemanticInfo semanticInfo(root);
    semanticInfo.FillInfo();

    std::vector<int>* numStr = semanticInfo.GetVectorNumerationStr();
    if(!std::is_sorted(numStr->begin(), numStr->end()))
        throw ParserException{0, QString("Нумерация строк не по порядку")};

    std::map<int, char>* declarationVar = semanticInfo.GetMapDeclarationVar();
    for(auto it : *declarationVar)
    {
        for(auto it_next : *declarationVar)
        {
            if(it_next.second == it.second && it_next.first != it.first)
                throw ParserException {it_next.first, (QString("Повторное объявление переменной %1 в строке %2").arg(it_next.second).arg(it_next.first))};
        }
    }

    numReturn = semanticInfo.GetNumStrReturn();
    numGoSub = semanticInfo.GetNumStrGoSub();
    numLinkGoSub = semanticInfo.GetLinkGOSUB();

    if(numGoSub->size() > numReturn->size())
        throw ParserException{0, QString("Оператор GOSUB не имеет RETURN строка %1").arg(numGoSub->back())};
}

void ParserProcessor::Translation()
 {
     QString line;
     bool flagTab = false;
     ToPython(root, line, flagTab);
 }

 //Добавить input и gosub
void ParserProcessor::ToPython(VirtualBaseNode *node, QString &result, bool flagTab)
{
    if(node == nullptr || node->GetVisitFlag() == true)
        return;

    node->SetEnabledVisitFlag();
    bool printFlag = false;
    switch (node->GetType())
    {
    case TypeNode::NUM_STATM:
    {
        auto VectorInputNode = node->GetVectorNodes();
        ToPython(VectorInputNode[0], result, flagTab);
        qDebug() << result;
        qDebug() << numLinkGoSub->size();
        if (std::find(numLinkGoSub->begin(), numLinkGoSub->end(), result.toInt()) != numLinkGoSub->end())
        {
            QString nameFunction = "def func_" + result + "():";
            result.clear();
            flagTab = true;
            ToPython(VectorInputNode[0], result, flagTab);
            flagTab = false;
        }
        break;
    }
    case TypeNode::INPUT:
    {
        auto VectorInputNode = node->GetVectorNodes();
        if(flagTab)
            result += "\t";
        ToPython(VectorInputNode[0], result, flagTab);
        result += " = int(input())";
        printFlag = true;
        break;
    }
    case TypeNode::PRINT:
    {
        if(flagTab)
            result += "\t";
       result += "print( ";
       auto VectorPrintNode = node->GetVectorNodes();
       ToPython(VectorPrintNode[0], result, flagTab);
       result += ")";
       printFlag = true;
       break;
    }
    case TypeNode::DIM:
    {
        auto VectorNextNode = node->GetVectorNodes();
        if(flagTab)
            result += "\t";
        ToPython(VectorNextNode[0], result, flagTab);
        result += " = None";
        printFlag = true;
        break;
    }
    case TypeNode::REM:
    {
        result += "#";
        auto VectorNextNode = node->GetVectorNodes();
        ToPython(VectorNextNode[0], result, flagTab);
        printFlag = true;
        break;
    }
    case TypeNode::GOSUB:
    {
        result += "func_";
        auto VectorNextNode = node->GetVectorNodes();
        ToPython(VectorNextNode[0], result, flagTab);
        result += "()";
        break;
    }
    case TypeNode::IF_THEN:
    {
        auto VectorIfNode = node->GetVectorNodes();
        if(flagTab)
            result += "\t";
        result = "if ";
        this->ToPython(VectorIfNode[0], result, flagTab);
        this->ToPython(VectorIfNode[1], result, flagTab);
        this->ToPython(VectorIfNode[2], result, flagTab);
        result += ": \n";
        result += '\t';
        this->ToPython(VectorIfNode[3], result, flagTab);
        printFlag = true;
        break;
    }
    case TypeNode::LET:
    {
        auto VectorNextNode = node->GetVectorNodes();
        if(flagTab)
            result += "\t";
        ToPython(VectorNextNode[0], result, flagTab);
        result += " = ";
        ToPython(VectorNextNode[1], result, flagTab);
        printFlag = true;
        break;
    }
    case TypeNode::RETRN:
    {
        if(flagTab)
            result += "\t";
        result = "return";
        printFlag = true;
        break;
    }
    case TypeNode::EXPR_LST:
    {
        auto VectorNextNode = node->GetVectorNodes();
        for (auto i = VectorNextNode.begin(); i < VectorNextNode.end(); i++)
        {
             ToPython(*i, result, flagTab);
             result += " ,";
        }
        break;
    }
    case TypeNode::VAR_LST:
    {
        auto VectorNextNode = node->GetVectorNodes();
        for (auto i = VectorNextNode.begin(); i < VectorNextNode.end(); i++)
        {
             ToPython(*i, result, flagTab);
             result += " ,";
        }

        break;
    }
    case TypeNode::EX_SUB_TERM:
    {
        auto VectorNextNode = node->GetVectorNodes();
        ToPython(VectorNextNode[0], result, flagTab);
        result += " - ";
        ToPython(VectorNextNode[1], result, flagTab);
        break;
    }
    case TypeNode::EX_ADD_TERM:
    {
        auto VectorNextNode = node->GetVectorNodes();
        ToPython(VectorNextNode[0], result, flagTab);
        result += " + ";
        ToPython(VectorNextNode[1], result, flagTab);
        break;
    }
    case TypeNode::TERM_MALT_FACT:
    {
        auto VectorNextNode = node->GetVectorNodes();
        ToPython(VectorNextNode[0], result, flagTab);
        result += " * ";
        ToPython(VectorNextNode[1], result, flagTab);
        break;
    }
    case TypeNode::TERM_DIVIDE_FACT:
    {
        auto VectorNextNode = node->GetVectorNodes();
        ToPython(VectorNextNode[0], result, flagTab);
        result += " / ";
        ToPython(VectorNextNode[1], result, flagTab);
        break;
    }
    case TypeNode::EXPRESSION_ALLOC:
    {
        result += "( ";
        auto VectorNextNode = node->GetVectorNodes();
        ToPython(VectorNextNode[0], result, flagTab);
        result += " )";
        break;
    }
    case TypeNode::INTEGER:
    {
        result += QString::fromStdString(node->GetValue());
        return;
    }
    case TypeNode::NUMBER_DG:
    {
        auto VectorNextNode = node->GetVectorNodes();
        for (auto i = VectorNextNode.begin(); i < VectorNextNode.end(); i++)
            ToPython(*i, result, flagTab);
        return;
    }
    case TypeNode::VARIABLE:
    {
        result += QString::fromStdString(node->GetValue());
        return;
    }
    case TypeNode::STRING:
    {
        result += QString::fromStdString(node->GetValue());
        return;
    }
    case TypeNode::LT:
    {
        result += " < ";
        return;
    }
    case TypeNode::LE:
    {
        result += " <= ";
        return;
    }
    case TypeNode::GT:
    {
        result += " > ";
        return;
    }
    case TypeNode::GE:
    {
        result += " >= ";
        return;
    }
    case TypeNode::EQ:
    {
        result += " == ";
        return;
    }
    case TypeNode::NE:
    {
        result += " != ";
        return;
    }
    default:
        break;
    }
    if(!result.isEmpty() && printFlag)
    {
        emit ResultToArea(result);
        result.clear();
    }

    auto VectorNextNode = node->GetVectorNodes();
    for (auto i = VectorNextNode.begin(); i < VectorNextNode.end(); i++)
        ToPython(*i, result, flagTab);

}
