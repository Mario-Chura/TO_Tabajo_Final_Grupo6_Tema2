#include "registrousuario.h"
#include "ui_registrousuario.h"

Registrousuario::Registrousuario(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Registrousuario)
{
    ui->setupUi(this);
}

Registrousuario::~Registrousuario()
{
    delete ui;
}
