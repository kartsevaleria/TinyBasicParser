#include "fabricnode.h"
#include <memory>

VirtualBaseNode* FabricNode::FabricNode::CreateNode(int line, TypeNode type)
{
    VirtualBaseNode* node = new RelopNode(line, type);
    return node;
}

VirtualBaseNode* FabricNode::CreateNode(int line, TypeNode type, std::string value)
{
    VirtualBaseNode* node = new ValueNode(line, type, value);
    return node;
}

VirtualBaseNode* FabricNode::CreateNode(int line, TypeNode type, VirtualBaseNode* left, VirtualBaseNode* rigth)
{
    VirtualBaseNode* node = new DefaultNode(line, type, left, rigth);
    return node;
}

VirtualBaseNode* FabricNode::CreateNode(int line, TypeNode type, VirtualBaseNode* one, VirtualBaseNode* two, VirtualBaseNode* three, VirtualBaseNode* four)
{
    VirtualBaseNode* node = new IfNode(line, type, one, two, three, four);
    return node;
}
