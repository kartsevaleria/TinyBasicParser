#ifndef RELOPNODE_H
#define RELOPNODE_H

#include "virtualbasenode.h"
#include "define_type.h"
#include <iostream>

class RelopNode : public VirtualBaseNode
{
private:
    TypeNode type;
    int lineno;
public:
    RelopNode(int line, TypeNode t): type(t), lineno(line) {};

    TypeNode GetType() override { return this->type; }
    int GetLineno() override { return this->lineno; }
    std::string GetValue() override { return "ERROR"; }

    void NextStepDown() override
    {
      return;
    }

};

#endif // RELOPNODE_H
