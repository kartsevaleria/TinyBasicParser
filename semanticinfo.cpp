#include "semanticinfo.h"
#include <QDebug>
//extern VirtualBaseNode* root;

void SemanticInfo::FillInfo()
{
    bool flagNumStr = false;
    bool flagDIM = false;
    bool flagGOSUB = false;
    bool flagLET = false;
    QString tempStr = "";
    treeTravel(this->root, flagNumStr, flagDIM, flagGOSUB, flagLET, tempStr);
    qDebug() << *linkGOSUB;
}

bool findByValue(std::map<int, char> mapOfElement, char elem)
{
    bool isFind = false;
    for(auto i = mapOfElement.begin(); i != mapOfElement.end(); i++ )
    {
        if(i->second == elem)
        {
            isFind = true;
            break;
        }
    }
    return isFind;
}

void SemanticInfo::treeTravel(VirtualBaseNode* currentNode, bool flagNumStr, bool flagDIM, bool flagGOSUB, bool flagLET, QString &tempStr)
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
    case TypeNode::INPUT:
    {
        flagLET = true;
        auto vectorNextNode = currentNode->GetVectorNodes();
        treeTravel(vectorNextNode[0], flagNumStr, flagDIM, flagGOSUB, flagLET, tempStr);
        flagLET = true;
        break;
    }
    case TypeNode::DIM:
    {
        //Что делать, если одинаковую переменную попытаются объявить в одной строке?
        flagDIM = true;
        auto vectorNextNode = currentNode->GetVectorNodes();
        treeTravel(vectorNextNode[0], flagNumStr, flagDIM, flagGOSUB, flagLET, tempStr);
        flagDIM = false;
        break;
    }
    case TypeNode::LET:
    {
        flagLET = true;
        auto vectorNextNode = currentNode->GetVectorNodes();
        treeTravel(vectorNextNode[0], flagNumStr, flagDIM, flagGOSUB, flagLET, tempStr);
        flagLET = false;
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
        treeTravel(vectorNextNode[0], flagNumStr, flagDIM, flagGOSUB, flagLET, tempStr);
        flagGOSUB = false;
        break;
    }
    case TypeNode::NUMBER_DG:
    {
        if(flagGOSUB)
        {
            auto vectorNextNode = currentNode->GetVectorNodes();
            for(auto i = vectorNextNode.begin(); i < vectorNextNode.end(); i++ )
                treeTravel(*i, flagNumStr, flagDIM, flagGOSUB, flagLET, tempStr);
            this->linkGOSUB->push_back(tempStr.toInt());
            tempStr.clear();
            break;
        }

        if(!flagNumStr)
            break;

        flagNumStr = false;
        auto vectorNextNode = currentNode->GetVectorNodes();
        for(auto i = vectorNextNode.begin(); i < vectorNextNode.end(); i++ )
            treeTravel(*i, flagNumStr, flagDIM, flagGOSUB, flagLET, tempStr);
        this->vectorNumerationStr->push_back(tempStr.toInt());
        tempStr.clear();
        break;
    }
    case TypeNode::DIGIT:
    {
        if(flagGOSUB)
        {
            auto vectorNextNode = currentNode->GetVectorNodes();
            treeTravel(vectorNextNode[0], flagNumStr, flagDIM, flagGOSUB, flagLET, tempStr);
            this->linkGOSUB->push_back(tempStr.toInt());
            tempStr.clear();
            break;
        }

        if(flagNumStr)
        {
            auto vectorNextNode = currentNode->GetVectorNodes();
            treeTravel(vectorNextNode[0], flagNumStr, flagDIM, flagGOSUB, flagLET, tempStr);
            this->vectorNumerationStr->push_back(tempStr.toInt());
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
        else if(flagLET)
            mapInitVar->insert(std::pair<int, char>(currentNode->GetLineno(), currentNode->GetValue()[0]));
        else
            mapUsingVar->insert(std::pair<int, char>(currentNode->GetLineno(), currentNode->GetValue()[0]));
        break;
    }
    default:
        break;
    }

    auto vectorNextNode = currentNode->GetVectorNodes();
    for(auto i = vectorNextNode.begin(); i < vectorNextNode.end(); i++ )
    {
        treeTravel(*i, flagNumStr, flagDIM, flagGOSUB, flagLET, tempStr);
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
