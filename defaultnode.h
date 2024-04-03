#ifndef DEFAULTNODE_H
#define DEFAULTNODE_H

#include "virtualbasenode.h"
#include "define_type.h"
#include <iostream>

class DefaultNode : public VirtualBaseNode
{
private:
    VirtualBaseNode* left;
    VirtualBaseNode* rigth;
    TypeNode type;
    int lineno;
public:
    DefaultNode();

    TypeNode GetType() override { return this->type; }
    int GetLineno() override { return this->lineno; }
    std::string GetValue() override { return "ERROR"; }

    void NextStepDown() override
    {
      this->left->NextStepDown();
      this->rigth->NextStepDown();
    }

};

#endif // DEFAULTNODE_H
