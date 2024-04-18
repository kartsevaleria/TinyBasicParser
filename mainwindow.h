#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aboutprogramform.h"
#include <QDateTime>


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
    void show_MessageProtocol(QString text);

private:
    Ui::MainWindow *ui;
    QString PathToInputFile;
    void resetResultArea();
    void addResultArea(int max, Qt::AlignmentFlag align);
};
#endif // MAINWINDOW_H
