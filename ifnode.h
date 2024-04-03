#ifndef IFNODE_H
#define IFNODE_H

#include "virtualbasenode.h"
#include "define_type.h"
#include <iostream>
#include <memory>


class IfNode : public VirtualBaseNode
{
private:
    U_PtrNode left_stat;
    U_PtrNode rigth_stat;
    U_PtrNode then_stat;
    U_PtrNode relop;
    TypeNode type;
    int lineno;
public:
    IfNode(int line, TypeNode t, U_PtrNode ls, U_PtrNode rs, U_PtrNode ts, U_PtrNode rlp)
    {
        left_stat = std::move(ls);
        rigth_stat = std::move(rs);
        then_stat = std::move(ts);
        relop = std::move(rlp);
        lineno = line;
        type = t;
    };

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
