#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QLabel>
#include <QSpinBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->parser = new ParserProcessor;
    ui->actionStart->setDisabled(1);

    //this->show_MessageProtocol("Начало работы.");
    QObject::connect(this, &MainWindow::MessageToProtocol, this, &MainWindow::show_MessageProtocol);
    QObject::connect(this, &MainWindow::ErrorToProtocol, this, &MainWindow::show_ErrorProtocol);
    QObject::connect(parser, &ParserProcessor::ErrorToProtocol, this, &MainWindow::show_ErrorProtocol);
    QObject::connect(parser, &ParserProcessor::ResultToArea, this, &MainWindow::print_ResultToArea);
    emit MessageToProtocol("Начало работы");
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
        ui->actionStart->setEnabled(0);

        return;
    }
    else
    {
        ui->BrowserInputText->clear();
        PathToInputFile = path;
        ui->actionStart->setEnabled(1);
        QFile f(PathToInputFile);
        f.open(QFile::ReadOnly);
        ui->BrowserInputText->append(f.readAll());
        this->show_MessageProtocol("Успешное открытие файла " + PathToInputFile);
    }

}



void MainWindow::on_AboutProgram_triggered()
{
    AboutProgramForm *f = new AboutProgramForm;
    f->show();
}

void MainWindow::show_MessageProtocol(QString text)
{
    QString time = QDateTime::currentDateTime().toString("HH:mm:ss");
    ui->BrowserProtocol->setTextBackgroundColor(QColor(0, 0, 0, 0));
    ui->BrowserProtocol->append(time + ": " + text);
}

void MainWindow::show_ErrorProtocol(QString text)
{
    QString time = QDateTime::currentDateTime().toString("HH:mm:ss");
    ui->BrowserProtocol->setTextBackgroundColor(QColor(255, 0, 0, 127));
    ui->BrowserProtocol->append(time + ": " + text );
}

void MainWindow::print_ResultToArea(QString text)
{
    ui->BrowserOutputText->append(text);
}



void MainWindow::on_actionStart_triggered()
{
    if (PathToInputFile.isEmpty()) {
        //Add output error
        this->show_ErrorProtocol("Не удалось открыть файл");
        return;
    }
    ui->actionStart->setEnabled(0);
    emit MessageToProtocol("Начало транслирования файла: " + PathToInputFile);
    QFile f(PathToInputFile);
    f.open(QFile::ReadOnly);
    QByteArray content(f.readAll());

    ui->BrowserOutputText->clear();
    parser->SetData(content);
    if(parser->BisonParser() != 0)
        return;
    emit MessageToProtocol("Синтаксический разбор: успешно");
    try {
        parser->SemanticAnalys();
    }  catch (ParserException &e) {
        emit ErrorToProtocol(QString("Semantic error: %1").arg(e.what));
        return;
    }
    emit MessageToProtocol("Семантический разбор: успешно");

    parser->Translation();
    emit MessageToProtocol("Трансляция: успешно");
}

