#include "mainwindow.h"
#include "BasicParser.h"
#include "BasicScanner.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
