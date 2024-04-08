#ifndef DEFAULTNODE_H
#define DEFAULTNODE_H

#include "virtualbasenode.h"
#include "define_type.h"
#include <iostream>
#include <memory>


class DefaultNode : public VirtualBaseNode
{
private:
    VirtualBaseNode* left;
    VirtualBaseNode* rigth;
    TypeNode type;
    int lineno;
public:
    DefaultNode(int line, TypeNode type, VirtualBaseNode* left, VirtualBaseNode* rigth) :
        lineno(line), type(type), left(left), rigth(rigth) {};

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
