#ifndef VIRTUALBASENODE_H
#define VIRTUALBASENODE_H

#include "define_type.h"
#include <string>
#include <vector>

class VirtualBaseNode
{
public:
    virtual TypeNode GetType() = 0;
    virtual int GetLineno() = 0;

    //relop, variable, string, int
    virtual std::string GetValue() = 0;
    virtual std::vector<VirtualBaseNode*> GetVectorNodes() = 0;
    virtual void SetEnabledVisitFlag();
    virtual bool GetVisitFlag();
    virtual ~VirtualBaseNode() = default;

};

//typedef  std::unique_ptr<VirtualBaseNode> U_PtrNode;

#endif // VIRTUALBASENODE_H
