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
    flagOnlyError = false;

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
        //ui->actionStart->setEnabled(0);

        return;
    }
    else
    {
        ui->BrowserInputText->clear();
        PathToInputFile = path;
        //ui->actionStart->setEnabled(1);
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
    if(flagOnlyError)
        return;
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
    emit MessageToProtocol("Начало транслирования файла: " + PathToInputFile);
    QString contentString = ui->BrowserInputText->toPlainText();
    QByteArray content = contentString.toUtf8();
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


void MainWindow::on_actionClearProtocol_triggered()
{
    ui->BrowserProtocol->clear();
}


void MainWindow::on_actionEdit_triggered()
{
    if(ui->actionEdit->isChecked())
        ui->BrowserInputText->setReadOnly(false);
    else
        ui->BrowserInputText->setReadOnly(true);
}


void MainWindow::on_actionOnlyError_triggered()
{
    flagOnlyError = ui->actionOnlyError->isChecked();
}

void MainWindow::saveOutputFile()
{
    QString result = ui->BrowserOutputText->toPlainText();
    if(result.isEmpty())
    {
        emit ErrorToProtocol("Не удалось сохранить результат. Файл пуст.");
        return;
    }
    QString path = QFileDialog::getSaveFileName(this, "Сохранение файла", QDir::current().absolutePath());
    QFile out(path);
    if(out.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&out);
        stream << result;
        out.close();
    }
}

void MainWindow::on_SaveAs_triggered()
{
    saveOutputFile();
}


void MainWindow::on_actionSaveResult_triggered()
{
    saveOutputFile();
}

