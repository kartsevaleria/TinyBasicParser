#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aboutprogramform.h"
#include <QDateTime>
#include "parserprocessor.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_BrowseFile_triggered();
    void on_StartButton_clicked();
    void on_AboutProgram_triggered();

    void on_ClearProtocolButton_clicked();

public slots:
    void show_MessageProtocol(QString text);
    void show_ErrorProtocol(QString text);
    void print_ResultToArea(QString text);

private:
    Ui::MainWindow *ui;
    QString PathToInputFile;
    ParserProcessor *parser;
    void resetResultArea();
    void addResultArea(int max, Qt::AlignmentFlag align);

signals:
    void MessageToProtocol(QString text);
    void ErrorToProtocol(QString text);
};
#endif // MAINWINDOW_H
