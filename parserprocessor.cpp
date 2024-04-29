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
    if(node == nullptr)
        return;

    switch (node->GetType())
    {
    case TypeNode::LINE:
    {
        if(result.isEmpty())
            break;
        else
        {
            ListPythonString.push_back(result);
            result = "";
            break;
        }

    }
    default:
        break;
    }

    auto VectorNextNode = node->GetVectorNodes();
    for (auto i = VectorNextNode.begin(); i < VectorNextNode.end(); i++)
        ToPython(*i, result);

}
