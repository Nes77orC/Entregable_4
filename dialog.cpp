#include "widget.h"
#include "ui_widget.h"
#include "iostream"
#include "dialog.h"
#include "ui_dialog.h"
#include <QString>



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
  accept();
}

void Dialog::on_buttonBox_rejected()
{
 reject();
}



QString Dialog::nombre()
{
return ui->nombre->text();
}

QString Dialog::materia()
{
return ui->materia->currentText();
}
QString Dialog::contrato()
{
return ui->contrato->currentText();
}











