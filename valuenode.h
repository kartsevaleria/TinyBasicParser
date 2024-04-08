#ifndef VALUENODE_H
#define VALUENODE_H

#include "virtualbasenode.h"
#include "define_type.h"
#include <iostream>

class ValueNode : public VirtualBaseNode
{
private:
    TypeNode type;
    int lineno;
    std::string value;
public:
    ValueNode(int line, TypeNode t, std::string val): type(t), lineno(line), value(val) {};

    TypeNode GetType() override { return this->type; }
    int GetLineno() override { return this->lineno; }
    std::string GetValue() override { return this->value; }

    void NextStepDown() override
    {
      return;
    }

};

#endif // VALUENODE_H
