#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QLabel>
#include <QSpinBox>
#include "parserprocessor.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BrowseFile_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Choose file", QDir::current().absolutePath(), "Sample input files (*.txt)");
    if (path.isEmpty()) {
        ui->FilePath->clear();
        return;
    }

    QFileInfo fi(path);
    ui->FilePath->setText(fi.fileName());
    ui->FilePath->setToolTip(path);

}


void MainWindow::on_StartParser_clicked()
{
    if (ui->FilePath->text().isEmpty()) {
        return;
    }

    QFile f(ui->FilePath->toolTip());
    f.open(QFile::ReadOnly);
    QByteArray content(f.readAll());
    ParserProcessor parser(content);


}

void MainWindow::resetResultArea()
{

}



