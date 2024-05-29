#ifndef DEFAULTNODE_H
#define DEFAULTNODE_H

#include "virtualbasenode.h"
#include "define_type.h"
#include <iostream>
#include <memory>
#include <vector>


class DefaultNode : public VirtualBaseNode
{
private:
    VirtualBaseNode* left;
    VirtualBaseNode* rigth;
    TypeNode type;
    int lineno;
    std::vector<VirtualBaseNode*> VectorChild;
    bool visitFlag;
public:
    DefaultNode(int line, TypeNode type, VirtualBaseNode* left, VirtualBaseNode* rigth) :
        lineno(line), type(type), left(left), rigth(rigth)
    {
        VectorChild.push_back(left);
        VectorChild.push_back(rigth);
        visitFlag = false;
    }

    TypeNode GetType() override { return this->type; }
    int GetLineno() override { return this->lineno; }
    std::string GetValue() override { return "ERROR"; }
    void SetEnabledVisitFlag() override { visitFlag = true; }
    std::vector<VirtualBaseNode*> GetVectorNodes() override { return VectorChild; }
    bool GetVisitFlag() override { return this->visitFlag; }
};

#endif // DEFAULTNODE_H
