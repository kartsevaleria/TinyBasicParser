#ifndef VIRTUALBASENODE_H
#define VIRTUALBASENODE_H

#include "define_type.h"
#include <vector>
#include <memory>


class VirtualBaseNode
{
public:
    VirtualBaseNode();
    virtual TypeNode GetType() = 0;
    virtual int GetLineno() = 0;

//    virtual std::vector<std::shared_ptr<VirtualBaseNode>> GetVectorNodes() = 0;

};

#endif // VIRTUALBASENODE_H
