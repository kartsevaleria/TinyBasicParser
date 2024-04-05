#ifndef VIRTUALBASENODE_H
#define VIRTUALBASENODE_H

#include "define_type.h"
#include <string>
#include <memory>

class VirtualBaseNode
{
public:
    virtual TypeNode GetType() = 0;
    virtual int GetLineno() = 0;

    //relop, variable, string, int
    virtual std::string GetValue() = 0;

    //not return *lest/rigth, process in function child class
    //return exit code or later add debug in realize function
    virtual void NextStepDown() = 0;

//    virtual std::vector<std::shared_ptr<VirtualBaseNode>> GetVectorNodes() = 0;
    virtual ~VirtualBaseNode() = default;

};

typedef  std::unique_ptr<VirtualBaseNode> U_PtrNode;

#endif // VIRTUALBASENODE_H
