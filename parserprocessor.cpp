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

//Записывать не во временный файл, а в буфеер ОП?
 int ParserProcessor::Translation()
 {
     //std::shared_ptr<ListStringResult> root_result (new ListStringResult);
     ToPython(root, "");
     return 0;
 }

void ParserProcessor::ToPython(VirtualBaseNode *node, QString result)
{
    if(node == nullptr || node->GetVisitFlag() == true)
        return;

    node->SetEnabledVisitFlag();
    switch (node->GetType())
    {
    case TypeNode::IF_THEN:
    {
        auto VectorIfNode = node->GetVectorNodes();
        result = "if ";

        //emit ResultToArea("if ");
        //Вызов функции для левого
        this->ToPython(VectorIfNode[0], result);

    }
    case TypeNode::LET:
    {
        auto VectorNextNode = node->GetVectorNodes();
        for (auto i = VectorNextNode.begin(); i < VectorNextNode.end(); i++)
             ToPython(*i, result);

        break;
    }
    case TypeNode::RETRN:
    {
        result = "return";
        break;
    }
    case TypeNode::EXPR_LST:
    {
        auto VectorNextNode = node->GetVectorNodes();
        for (auto i = VectorNextNode.begin(); i < VectorNextNode.end(); i++)
        {
             ToPython(*i, result);
             result += " ,";
        }

        break;
    }
    case TypeNode::VAR_LST:
    {
        auto VectorNextNode = node->GetVectorNodes();
        for (auto i = VectorNextNode.begin(); i < VectorNextNode.end(); i++)
        {
             ToPython(*i, result);
             result += " ,";
        }

        break;
    }
    case TypeNode::EX_SUB_TERM:
    {
        auto VectorNextNode = node->GetVectorNodes();
        ToPython(VectorNextNode[0], result);
        result += " - ";
        ToPython(VectorNextNode[1], result);
        break;
    }
    case TypeNode::EX_ADD_TERM:
    {
        auto VectorNextNode = node->GetVectorNodes();
        ToPython(VectorNextNode[0], result);
        result += " + ";
        ToPython(VectorNextNode[1], result);
        break;
    }
    case TypeNode::TERM_MALT_FACT:
    {
        auto VectorNextNode = node->GetVectorNodes();
        ToPython(VectorNextNode[0], result);
        result += " * ";
        ToPython(VectorNextNode[1], result);
        break;
    }
    case TypeNode::TERM_DIVIDE_FACT:
    {
        auto VectorNextNode = node->GetVectorNodes();
        ToPython(VectorNextNode[0], result);
        result += " / ";
        ToPython(VectorNextNode[1], result);
        break;
    }
    case TypeNode::EXPRESSION:
    {
        result += "( ";
        auto VectorNextNode = node->GetVectorNodes();
        ToPython(VectorNextNode[0], result);
        result += " )";
        break;
    }
    case TypeNode::INTEGER:
    {
        result += QString::fromStdString(node->GetValue());
        break;
    }
    case TypeNode::NUMBER_DG:
    {
        auto VectorNextNode = node->GetVectorNodes();
        for (auto i = VectorNextNode.begin(); i < VectorNextNode.end(); i++)
            ToPython(*i, result);
        break;
    }
    case TypeNode::VARIABLE:
    {
        result += QString::fromStdString(node->GetValue());
        break;
    }
    case TypeNode::STRING:
    {
        result += QString::fromStdString(node->GetValue());
        break;
    }
    case TypeNode::LT:
    {
        result += " < ";
        break;
    }
    case TypeNode::LE:
    {
        result += " <= ";
        break;
    }
    case TypeNode::GT:
    {
        result += " > ";
        break;
    }
    case TypeNode::GE:
    {
        result += " >= ";
        break;
    }
    case TypeNode::EQ:
    {
        result += " == ";
        break;
    }
    case TypeNode::NE:
    {
        result += " != ";
        break;
    }
    default:
        break;
    }

    emit ResultToArea(result);
    result.clear();
    auto VectorNextNode = node->GetVectorNodes();
    for (auto i = VectorNextNode.begin(); i < VectorNextNode.end(); i++)
        ToPython(*i, result);

}
