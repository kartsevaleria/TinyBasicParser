#ifndef PARSERPROCESSOR_H
#define PARSERPROCESSOR_H


#include <QVector>

#include "common.h"
#include "BasicParser.h"
#include "BasicScanner.h"

class YYBufferGuard
{
    YY_BUFFER_STATE* mState;
public:
    YYBufferGuard(YY_BUFFER_STATE *state);
    ~YYBufferGuard();
};

class ParserProcessor
{
    //elements_t mElements;
private:
    QByteArray data;
public:
    ParserProcessor(QByteArray data);
    //elements_t& elements();
    int BisonParser();
    int SemanticAnalys();
    int Translation();
};

#endif // PARSERPROCESSOR_H
