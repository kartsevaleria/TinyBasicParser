#include "fabricnode.h"
#include <memory>


U_PtrNode CreateNode(int line, TypeNode type)
{
    U_PtrNode node = std::make_unique<RelopNode>(line, type);
    return (move(node));
}

U_PtrNode CreateNode(int line, TypeNode type, std::string value)
{
    U_PtrNode node = std::make_unique<ValueNode>(line, type, value);
    return (move(node));
}

U_PtrNode CreateNode(int line, TypeNode type, U_PtrNode left, U_PtrNode rigth)
{
    U_PtrNode node = std::make_unique<DefaultNode>(line, type, move(left), move(rigth));
    return (move(node));
}

U_PtrNode CreateNode(int line, TypeNode type, U_PtrNode one, U_PtrNode two, U_PtrNode three, U_PtrNode four)
{
    U_PtrNode node = std::make_unique<IfNode>(line, type, move(one), move(two), move(three), move(four));
    return (move(node));
}
