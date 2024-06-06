#ifndef SEMANTICINFO_H
#define SEMANTICINFO_H
#include <QByteArray>
#include <vector>
#include <map>
#include "virtualbasenode.h"

class SemanticInfo
{
private:
    VirtualBaseNode *root;
    std::map<int, char>* mapDeclarationVar;
    std::vector<int>* vectorNumerationStr;
    std::vector<int>* numStringReturn;
    std::vector<int>* numStringGOSUB;
    std::vector<int>* linkGOSUB;
    void treeTravel(VirtualBaseNode* currentNode, bool flagNumStr, bool flagDIM, bool flagGOSUB, QString &tempStr);
public:
    SemanticInfo(VirtualBaseNode *r) : root(r)
    {
        vectorNumerationStr = new std::vector<int>();
        mapDeclarationVar = new std::map<int, char>();
        numStringReturn = new std::vector<int>();
        numStringGOSUB = new std::vector<int>();
        linkGOSUB = new std::vector<int>();
    }
    void FillInfo();
    std::vector<int>* GetVectorNumerationStr() { return vectorNumerationStr; }
    std::vector<int>* GetNumStrReturn() { return numStringReturn; }
    std::vector<int>* GetNumStrGoSub() { return numStringGOSUB; }
    std::vector<int>* GetLinkGOSUB() { return linkGOSUB; }
    std::map<int, char>* GetMapDeclarationVar() { return mapDeclarationVar; }
};

#endif // SEMANTICINFO_H
