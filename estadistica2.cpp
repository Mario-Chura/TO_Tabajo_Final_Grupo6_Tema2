#include "estadistica2.h"
#include "ui_estadistica2.h"
#include "principal.h"

Estadistica2::Estadistica2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Estadistica2)
{
    ui->setupUi(this);
}

Estadistica2::~Estadistica2()
{
    delete ui;
}

void Estadistica2::on_menu_clicked()
{
    // Oculta la ventana actual (MainPage)
    this->hide();

    // Crea o obtén la instancia de la ventana llamada "principal"
    Principal *principal = new Principal();  // Asegúrate de que la clase se llama "Principal"

    // Muestra la ventana "principal"
    principal->show();
}

