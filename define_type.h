#ifndef DEFINE_TYPE_H
#define DEFINE_TYPE_H

#include <QString>

typedef enum class TypeNode
{
    NE = 1,
    EQ = 2,
    GE = 3,
    GT = 4,
    LE = 5,
    LT = 6,
    STRING = 7,
    VARIABLE = 8,
    INTEGER = 9,
    DIGIT = 10,
    NUMBER_DG = 11,
    EXPRESSION = 12,
    NUMBER = 13,
    VAR = 14,
    FACTOR = 15,
    TERM_DIVIDE_FACT = 16,
    TERM_MALT_FACT = 17,
    TERM = 18,
    EX_SUB_TERM = 19,
    EX_ADD_TERM = 20,
    VAR_LST = 21,
    EXPR_LST = 22,
    STR = 23,
    RETRN = 24,
    LET = 25,
    INPUT = 26,
    GOSUB = 27,
    IF_THEN = 28,
    DIM = 29,
    REM = 30,
    PRINT = 31,
    STATM = 32,
    NUM_STATM = 33,
    LINE = 34,
    BLOCK_LINE = 35,
    EXPRESSION_ALLOC = 36
} TypeNode;


#endif // DEFINE_TYPE_H
