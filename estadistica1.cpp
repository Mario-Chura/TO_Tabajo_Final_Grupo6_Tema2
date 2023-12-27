#include "estadistica1.h"
#include "ui_estadistica1.h"
#include "principal.h"

Estadistica1::Estadistica1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Estadistica1)
{
    ui->setupUi(this);
}

Estadistica1::~Estadistica1()
{
    delete ui;
}

void Estadistica1::on_menu_clicked()
{
    // Oculta la ventana actual (MainPage)
    this->hide();

    // Crea o obtén la instancia de la ventana llamada "principal"
    Principal *principal = new Principal();  // Asegúrate de que la clase se llama "Principal"

    // Muestra la ventana "principal"
    principal->show();
}

