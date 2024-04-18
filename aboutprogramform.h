#ifndef ABOUTPROGRAMFORM_H
#define ABOUTPROGRAMFORM_H

#include <QDialog>

namespace Ui {
class AboutProgramForm;
}

class AboutProgramForm : public QDialog
{
    Q_OBJECT

public:
    explicit AboutProgramForm(QWidget *parent = nullptr);
    ~AboutProgramForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AboutProgramForm *ui;
};

#endif // ABOUTPROGRAMFORM_H
