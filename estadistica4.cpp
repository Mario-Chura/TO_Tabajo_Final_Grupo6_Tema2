#include "estadistica4.h"
#include "ui_estadistica4.h"
#include "principal.h"

Estadistica4::Estadistica4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Estadistica4)
{
    ui->setupUi(this);
}

Estadistica4::~Estadistica4()
{
    delete ui;
}

void Estadistica4::on_menu_clicked()
{
    // Oculta la ventana actual (MainPage)
    this->hide();

    // Crea o obtén la instancia de la ventana llamada "principal"
    Principal *principal = new Principal();  // Asegúrate de que la clase se llama "Principal"

    // Muestra la ventana "principal"
    principal->show();
}

