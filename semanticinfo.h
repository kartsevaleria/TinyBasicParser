#ifndef SEMANTICINFO_H
#define SEMANTICINFO_H
#include <QByteArray>
#include <vector>
#include "virtualbasenode.h"

class SemanticInfo
{
private:
    VirtualBaseNode *root;
    std::vector<char> vectorDeclarationVar;
    std::vector<int> vectorNumerationStr;
    std::vector<int> numStringReturn;
    std::vector<int> numStringGOSUB;
public:
    SemanticInfo();
    void FillInfo(VirtualBaseNode* node);
};

#endif // SEMANTICINFO_H
