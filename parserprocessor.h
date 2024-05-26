#ifndef PARSERPROCESSOR_H
#define PARSERPROCESSOR_H


#include <QVector>

#include "common.h"
#include "BasicParser.h"
#include "BasicScanner.h"
#include <QObject>
#include <list>

class YYBufferGuard
{
    YY_BUFFER_STATE* mState;
public:
    YYBufferGuard(YY_BUFFER_STATE *state);
    ~YYBufferGuard();
};

class ParserProcessor : public QObject
{
    Q_OBJECT
private:
    QByteArray data;
    std::list<QString> ListPythonString;
    void ToPython(VirtualBaseNode* node, QString result);
public:
    ParserProcessor(QByteArray data);
    ParserProcessor() {};
    int BisonParser();
    int SemanticAnalys();
    int Translation();
    void SetData(QByteArray d);
signals:
    void ErrorToProtocol(QString text);
    void ResultToArea(QString text);
};

#endif // PARSERPROCESSOR_H
