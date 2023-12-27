#include "principal.h"
#include "ui_principal.h"
#include <QStandardItemModel>
#include "estadistica1.h"
#include "estadistica2.h"
#include "estadistica3.h"
#include "estadistica4.h"

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::on_CargaEncabezado_clicked()
{
    ui->tabla->setColumnCount(15);
    QStringList l;

}


void Principal::on_estadistica1_clicked()
{
    // Oculta la ventana actual (MainPage)
    this->hide();

    // Crea o obtén la instancia de la ventana llamada "principal"
    Estadistica1 *estadistica1 = new Estadistica1();  // Asegúrate de que la clase se llama "Principal"

    // Muestra la ventana "principal"
    estadistica1->show();
}


void Principal::on_estadistica2_clicked()
{
    // Oculta la ventana actual (MainPage)
    this->hide();

    // Crea o obtén la instancia de la ventana llamada "principal"
    Estadistica2 *estadistica2 = new Estadistica2();  // Asegúrate de que la clase se llama "Principal"

    // Muestra la ventana "principal"
    estadistica2->show();
}


void Principal::on_estadistica3_clicked()
{
    // Oculta la ventana actual (MainPage)
    this->hide();

    // Crea o obtén la instancia de la ventana llamada "principal"
    Estadistica3 *estadistica3 = new Estadistica3();  // Asegúrate de que la clase se llama "Principal"

    // Muestra la ventana "principal"
    estadistica3->show();
}


void Principal::on_estadistica4_clicked()
{
    // Oculta la ventana actual (MainPage)
    this->hide();

    // Crea o obtén la instancia de la ventana llamada "principal"
    Estadistica4 *estadistica4 = new Estadistica4();  // Asegúrate de que la clase se llama "Principal"

    // Muestra la ventana "principal"
    estadistica4->show();
}

