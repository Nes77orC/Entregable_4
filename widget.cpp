#include "widget.h"
#include "ui_widget.h"

#include "dialog.h"
#include "ui_dialog.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Resultados");
    QStringList titulos;
    titulos <<"Nombre" << "Materia" << "Jornada";
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(titulos);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{

    int resultado;
    int fila;
    QString nombre;
    QString materia;
    QString contrato;


Dialog objeto(this);
objeto.setWindowTitle("llenar formulario");
resultado=objeto.exec();

if(resultado==QDialog::Rejected)
    return;
nombre = objeto.nombre();
materia = objeto.materia();
contrato = objeto.contrato();

ui->tableWidget->insertRow(ui->tableWidget->rowCount());
fila=ui->tableWidget->rowCount()-1;
ui->tableWidget->setItem(fila, 0, new QTableWidgetItem(nombre));
ui->tableWidget->setItem(fila, 1, new QTableWidgetItem(materia));
ui->tableWidget->setItem(fila, 2, new QTableWidgetItem(contrato));

}
