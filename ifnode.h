#ifndef IFNODE_H
#define IFNODE_H

#include "virtualbasenode.h"
#include "define_type.h"
#include <iostream>
#include <memory>


class IfNode : public VirtualBaseNode
{
private:
    VirtualBaseNode* left_stat;
    VirtualBaseNode* rigth_stat;
    VirtualBaseNode* then_stat;
    VirtualBaseNode* relop;
    TypeNode type;
    int lineno;
public:
    IfNode(int line, TypeNode t, VirtualBaseNode* ls, VirtualBaseNode* rs, VirtualBaseNode* ts, VirtualBaseNode* rlp) :
        left_stat(ls), rigth_stat(rs), then_stat(ts), relop(rlp), type(t), lineno(line) {};

    TypeNode GetType() override { return this->type; }
    int GetLineno() override { return this->lineno; }
    std::string GetValue() override { return "ERROR"; }

    void NextStepDown() override
    {
      if (this->left_stat != nullptr)
        this->left_stat->NextStepDown();

      if (this->rigth_stat != nullptr)
        this->rigth_stat->NextStepDown();

      if (this->then_stat != nullptr)
        this->then_stat->NextStepDown();

      if (this->relop != nullptr)
        this->relop->NextStepDown();
    }

};

#endif // IFNODE_H
