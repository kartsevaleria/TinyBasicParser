#ifndef DEFAULTNODE_H
#define DEFAULTNODE_H

#include "virtualbasenode.h"
#include "define_type.h"
#include <iostream>
#include <memory>


class DefaultNode : public VirtualBaseNode
{
private:
    U_PtrNode left;
    U_PtrNode rigth;
    TypeNode type;
    int lineno;
public:
    DefaultNode(int line, TypeNode t, U_PtrNode l, U_PtrNode r)
    {
        left = std::move(l);
        rigth = std::move(r);
        lineno = line;
        type = t;
    };

    TypeNode GetType() override { return this->type; }
    int GetLineno() override { return this->lineno; }
    std::string GetValue() override { return "ERROR"; }

    void NextStepDown() override
    {
      if (this->left != nullptr)
        this->left->NextStepDown();
      if (this->rigth != nullptr)
        this->rigth->NextStepDown();
    }

};

#endif // DEFAULTNODE_H
