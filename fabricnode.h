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
    U_PtrNode CreateNode(int line, TypeNode type);
    U_PtrNode CreateNode(int line, TypeNode type, std::string value);
    U_PtrNode CreateNode(int line, TypeNode type, U_PtrNode one, U_PtrNode two, U_PtrNode three, U_PtrNode four);
    U_PtrNode CreateNode(int line, TypeNode type, U_PtrNode left, U_PtrNode rigth);
};

#endif // FABRICNODE_H
