#include "semanticinfo.h"
#include <QDebug>
//extern VirtualBaseNode* root;

void SemanticInfo::FillInfo()
{
    bool flagNumStr = false;
    bool flagDIM = false;
    bool flagGOSUB = false;
    QString tempStr = "";
    treeTravel(this->root, flagNumStr, flagDIM, flagGOSUB, tempStr);
    qDebug() << *linkGOSUB;
}

void SemanticInfo::treeTravel(VirtualBaseNode* currentNode, bool flagNumStr, bool flagDIM, bool flagGOSUB, QString &tempStr)
{
    if(currentNode == nullptr)
        return;

    switch (currentNode->GetType())
    {
    case TypeNode::NUM_STATM:
    {
        flagNumStr = true;
        tempStr.clear();
        break;
    }
    case TypeNode::STATM:
    {
        flagNumStr = false;
        tempStr.clear();
        break;
    }
    case TypeNode::DIM:
    {
        //Что делать, если одинаковую переменную попытаются объявить в одной строке?
        flagDIM = true;
        auto vectorNextNode = currentNode->GetVectorNodes();
        treeTravel(vectorNextNode[0], flagNumStr, flagDIM, flagGOSUB, tempStr);
        flagDIM = false;
        break;
    }
    case TypeNode::RETRN:
    {
        this->numStringReturn->push_back(currentNode->GetLineno());
        break;
    }
    case TypeNode::GOSUB:
    {
        this->numStringGOSUB->push_back(currentNode->GetLineno());
        auto vectorNextNode = currentNode->GetVectorNodes();
        flagGOSUB = true;
        treeTravel(vectorNextNode[0], flagNumStr, flagDIM, flagGOSUB, tempStr);
        flagGOSUB = false;
        break;
    }
    case TypeNode::NUMBER_DG:
    {
        if(!flagNumStr)
            break;
        flagNumStr = false;
        auto vectorNextNode = currentNode->GetVectorNodes();
        for(auto i = vectorNextNode.begin(); i < vectorNextNode.end(); i++ )
            treeTravel(*i, flagNumStr, flagDIM, flagGOSUB, tempStr);
        this->vectorNumerationStr->push_back(tempStr.toInt());
        if(flagGOSUB)
            this->linkGOSUB->push_back(tempStr.toInt());
        tempStr.clear();
        break;
    }
    case TypeNode::DIGIT:
    {
        if(flagNumStr)
        {
            auto vectorNextNode = currentNode->GetVectorNodes();
            treeTravel(vectorNextNode[0], flagNumStr, flagDIM, flagGOSUB, tempStr);
            this->vectorNumerationStr->push_back(tempStr.toInt());
            if(flagGOSUB)
                this->linkGOSUB->push_back(tempStr.toInt());
            tempStr.clear();
            flagNumStr = false;
        }
        break;
    }
    case TypeNode::INTEGER:
    {
        tempStr += QString::fromStdString(currentNode->GetValue());
        break;
    }
    case TypeNode::VARIABLE:
    {
        if(flagDIM)
            mapDeclarationVar->insert(std::pair<int, char>(currentNode->GetLineno(), currentNode->GetValue()[0]));
        break;
    }
    default:
        break;
    }

    auto vectorNextNode = currentNode->GetVectorNodes();
    for(auto i = vectorNextNode.begin(); i < vectorNextNode.end(); i++ )
    {
        treeTravel(*i, flagNumStr, flagDIM, flagGOSUB, tempStr);
    }
}

//Вызывыет ошибку: double free or corruption (out)
//SemanticInfo::~SemanticInfo()
//{
//    delete [] numStringGOSUB;
//    delete [] numStringReturn;
//    delete [] mapDeclarationVar;
//    delete [] vectorNumerationStr;

//    //Избежать болтающихся указателей
//    numStringGOSUB = nullptr;
//    numStringReturn = nullptr;
//    mapDeclarationVar = nullptr;
//    vectorNumerationStr = nullptr;
//}
