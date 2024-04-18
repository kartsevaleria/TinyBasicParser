#include "aboutprogramform.h"
#include "ui_aboutprogramform.h"

AboutProgramForm::AboutProgramForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutProgramForm)
{
    ui->setupUi(this);
}

AboutProgramForm::~AboutProgramForm()
{
    delete ui;
}

void AboutProgramForm::on_pushButton_clicked()
{
    this->close();
}

