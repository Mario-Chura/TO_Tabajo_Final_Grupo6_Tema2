#include "estadistica3.h"
#include "ui_estadistica3.h"
#include "principal.h"

Estadistica3::Estadistica3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Estadistica3)
{
    ui->setupUi(this);
}

Estadistica3::~Estadistica3()
{
    delete ui;
}

void Estadistica3::on_menu_clicked()
{
    // Oculta la ventana actual (MainPage)
    this->hide();

    // Crea o obtén la instancia de la ventana llamada "principal"
    Principal *principal = new Principal();  // Asegúrate de que la clase se llama "Principal"

    // Muestra la ventana "principal"
    principal->show();
}

