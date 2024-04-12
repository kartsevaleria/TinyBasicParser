#ifndef COMMON_H
#define COMMON_H

#include <QVector>

typedef struct ParserException {
    int lineNumber;
    QString what;
} ParserException;

#endif // COMMON_H
