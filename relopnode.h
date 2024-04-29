#ifndef RELOPNODE_H
#define RELOPNODE_H

#include "virtualbasenode.h"
#include "define_type.h"
#include <iostream>
#include <vector>

class RelopNode : public VirtualBaseNode
{
private:
    TypeNode type;
    int lineno;
    std::vector<VirtualBaseNode*> VectorChild;
public:
    RelopNode(int line, TypeNode t): type(t), lineno(line)
    {
        VectorChild.push_back(nullptr);
        VectorChild.push_back(nullptr);
    }

    TypeNode GetType() override { return this->type; }
    int GetLineno() override { return this->lineno; }
    std::string GetValue() override { return "ERROR"; }

     std::vector<VirtualBaseNode*> GetVectorNodes() override { return VectorChild; }

};

#endif // RELOPNODE_H
