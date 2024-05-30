#ifndef IFNODE_H
#define IFNODE_H

#include "virtualbasenode.h"
#include "define_type.h"
#include <iostream>
#include <memory>
#include <vector>


class IfNode : public VirtualBaseNode
{
private:
    VirtualBaseNode* left_stat;
    VirtualBaseNode* rigth_stat;
    VirtualBaseNode* then_stat;
    VirtualBaseNode* relop;
    TypeNode type;
    int lineno;
    std::vector<VirtualBaseNode*> VectorChild;
    bool visitFlag;
public:
    IfNode(int line, TypeNode t, VirtualBaseNode* ls, VirtualBaseNode* rlp, VirtualBaseNode* rs, VirtualBaseNode* ts) :
        left_stat(ls), rigth_stat(rs), then_stat(ts), relop(rlp), type(t), lineno(line)
    {
        VectorChild.push_back(left_stat);
        VectorChild.push_back(relop);
        VectorChild.push_back(rigth_stat);
        VectorChild.push_back(then_stat);
        visitFlag = false;
    }

    TypeNode GetType() override { return this->type; }
    int GetLineno() override { return this->lineno; }
    std::string GetValue() override { return "ERROR"; }
    void SetEnabledVisitFlag() override { visitFlag = true; }
    std::vector<VirtualBaseNode*> GetVectorNodes() override { return VectorChild; }
    bool GetVisitFlag() override { return this->visitFlag; }
};

#endif // IFNODE_H
