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
    std::map<int, char> mapDeclarationVar;
    std::vector<int> vectorNumerationStr;
    std::vector<int> numStringReturn;
    std::vector<int> numStringGOSUB;
    void treeTravel(VirtualBaseNode* currentNode, bool flagNumStr, bool flagDIM, QString tempStr);
public:
    SemanticInfo(VirtualBaseNode *r) : root(r) {};
    void FillInfo();
    std::vector<int> GetVectorNumerationStr() { return vectorNumerationStr; }
    std::vector<int> GetNumStrReturn() {return numStringReturn; }
    std::vector<int> GetNumStrGoSub() { return numStringGOSUB; }
    std::map<int, char> GetMapDeclarationVar() { return mapDeclarationVar; }
};

#endif // SEMANTICINFO_H
