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
    std::vector<VirtualBaseNode*> VectorChild;
    bool visitFlag;
public:
    ValueNode(int line, TypeNode t, std::string val): type(t), lineno(line), value(val)
    {
        VectorChild.push_back(nullptr);
        VectorChild.push_back(nullptr);
        visitFlag = false;
    }

    TypeNode GetType() override { return this->type; }
    int GetLineno() override { return this->lineno; }
    std::string GetValue() override { return this->value; }
    std::vector<VirtualBaseNode*> GetVectorNodes() override { return VectorChild; }
    void SetEnabledVisitFlag() override { visitFlag = true; }
    bool GetVisitFlag() override { return this->visitFlag; }
};

#endif // VALUENODE_H
