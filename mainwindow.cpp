#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QLabel>
#include <QSpinBox>
#include "parserprocessor.h"
    //add signal/slot for protocol
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->StartButton->setDisabled(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::resetResultArea()
{

}




void MainWindow::on_BrowseFile_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, "Choose file", QDir::current().absolutePath(), "Sample input files (*.txt)");
    if (path.isEmpty())
    {
        ui->StartButton->setEnabled(0);
        return;
    }
    else
    {
        PathToInputFile = path;
        ui->StartButton->setEnabled(1);
        QFile f(PathToInputFile);
        f.open(QFile::ReadOnly);
        ui->BrowserInputText->append(f.readAll());
    }

}


void MainWindow::on_StartButton_clicked()
{
    if (PathToInputFile.isEmpty()) {
        //Add output error
        return;
    }
    ui->StartButton->setEnabled(0);
    ui->BrowserProtocol->append("00:00. Начало транслирования файла: " + PathToInputFile);
    QFile f(PathToInputFile);
    f.open(QFile::ReadOnly);
    QByteArray content(f.readAll());
    ParserProcessor parser(content);
    parser.BisonParser();
    ui->BrowserProtocol->append("00:01. Синтаксический разбор: успешно");
    ui->BrowserProtocol->append("00:02. DONE!");
}

