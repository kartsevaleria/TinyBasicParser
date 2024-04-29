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

public:
    DefaultNode(int line, TypeNode type, VirtualBaseNode* left, VirtualBaseNode* rigth) :
        lineno(line), type(type), left(left), rigth(rigth)
    {
        VectorChild.push_back(left);
        VectorChild.push_back(rigth);
    }

    TypeNode GetType() override { return this->type; }
    int GetLineno() override { return this->lineno; }
    std::string GetValue() override { return "ERROR"; }

    std::vector<VirtualBaseNode*> GetVectorNodes() override { return VectorChild; }

};

#endif // DEFAULTNODE_H
