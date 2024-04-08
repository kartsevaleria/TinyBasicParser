#ifndef FABRICNODE_H
#define FABRICNODE_H
#include "define_type.h"
#include "virtualbasenode.h"
#include "defaultnode.h"
#include "ifnode.h"
#include "relopnode.h"
#include "valuenode.h"



class FabricNode
{
public:
    static VirtualBaseNode* CreateNode(int line, TypeNode type);
    static VirtualBaseNode* CreateNode(int line, TypeNode type, std::string value);
    static VirtualBaseNode* CreateNode(int line, TypeNode type, VirtualBaseNode* one, VirtualBaseNode* two, VirtualBaseNode* three, VirtualBaseNode* four);
    static VirtualBaseNode* CreateNode(int line, TypeNode type, VirtualBaseNode* left, VirtualBaseNode* rigth);
};

#endif // FABRICNODE_H
