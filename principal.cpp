#include "principal.h"
#include "ui_principal.h"
#include <QStandardItemModel>
#include "estadistica1.h"
#include "estadistica2.h"
#include "estadistica3.h"
#include "estadistica4.h"
#include "DataHolder.h"
#include <iostream>
#include "Registro.h"


Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
    f=-1;
}



Principal::~Principal()
{
    delete ui;
}

void Principal::on_estadistica1_clicked()
{
    // Oculta la ventana actual (MainPage)
    this->hide();

    // Crea o obtén la instancia de la ventana llamada "principal"
    Estadistica1 *estadistica1 = new Estadistica1();

    // Muestra la ventana "principal"
    estadistica1->show();
}


void Principal::on_estadistica2_clicked()
{
    // Oculta la ventana actual (MainPage)
    this->hide();

    // Crea o obtén la instancia de la ventana llamada "principal"
    Estadistica2 *estadistica2 = new Estadistica2();

    // Muestra la ventana "principal"
    estadistica2->show();
}


void Principal::on_estadistica3_clicked()
{
    // Oculta la ventana actual (MainPage)
    this->hide();

    // Crea o obtén la instancia de la ventana llamada "principal"
    Estadistica3 *estadistica3 = new Estadistica3();

    // Muestra la ventana "principal"
    estadistica3->show();
}


void Principal::on_estadistica4_clicked()
{
    // Oculta la ventana actual (MainPage)
    this->hide();

    // Crea o obtén la instancia de la ventana llamada "principal"
    Estadistica4 *estadistica4 = new Estadistica4();

    // Muestra la ventana "principal"
    estadistica4->show();
}


void Principal::on_CargaRegistro_clicked()
{
    ui->tabla->setColumnCount(15);
    QStringList l;
    l<<"FECHA_CORTE"<<"UUID"<<"FECHA_MUESTRA"<<"Edad"<<"Sexo"<<"Institucion"<<"UBIGEO_PACIENTE"<<"DEPARTAMENTO_PACIENTE"<<"PROVINCIA_PACIENTE"<<"DISTRITO_PACIENTE"<<"DEPARTAMENTO_MUESTRA"<<"PROVINCIA_MUESTRA"<<"DISTRITO_MUESTRA"<<"TIPO_MUESTRA"<<"RESULTADO";
    ui->tabla->setHorizontalHeaderLabels(l);
    ui->tabla->setColumnWidth(0, 200);
    ui->tabla->setColumnWidth(1, 200);
    ui->tabla->setColumnWidth(2, 200);
    ui->tabla->setColumnWidth(3, 200);
    ui->tabla->setColumnWidth(4, 200);
    ui->tabla->setColumnWidth(5, 200);
    ui->tabla->setColumnWidth(6, 200);
    ui->tabla->setColumnWidth(7, 200);
    ui->tabla->setColumnWidth(8, 200);
    ui->tabla->setColumnWidth(9, 200);
    ui->tabla->setColumnWidth(10, 200);
    ui->tabla->setColumnWidth(11, 200);
    ui->tabla->setColumnWidth(12, 200);
    ui->tabla->setColumnWidth(13, 200);
    ui->tabla->setColumnWidth(14, 200);



    AVLTree* tree = DataHolder::instance().getTree();
    // Limpiar la tabla antes de cargar nuevos datos
    ui->tabla->clearContents();
    ui->tabla->setRowCount(0);

    // Obtener todos los registros del árbol
    std::vector<Registro*> registros = tree->getAllRegistros();

    // Llenar la tabla con la información de los registros
    for (const auto& registro : registros) {
        int row = ui->tabla->rowCount();
        ui->tabla->insertRow(row);

        // Insertar datos en las celdas de la tabla

        ui->tabla->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(registro->getFechaCorte())));
        ui->tabla->setItem(row, 1, new QTableWidgetItem(QString::number(registro->getUuid())));
        ui->tabla->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(registro->getFechaMuestra())));
        ui->tabla->setItem(row, 3, new QTableWidgetItem(QString::number(registro->getEdad())));
        ui->tabla->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(registro->getSexo())));
        ui->tabla->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(registro->getInstitucion())));
        ui->tabla->setItem(row, 6, new QTableWidgetItem(QString::fromStdString(registro->getUbigeoPaciente())));
        ui->tabla->setItem(row, 7, new QTableWidgetItem(QString::fromStdString(registro->getDepartamentoPaciente())));
        ui->tabla->setItem(row, 8, new QTableWidgetItem(QString::fromStdString(registro->getProvinciaPaciente())));
        ui->tabla->setItem(row, 9, new QTableWidgetItem(QString::fromStdString(registro->getDistritoPaciente())));
        ui->tabla->setItem(row, 10, new QTableWidgetItem(QString::fromStdString(registro->getDepartamentoMuestra())));
        ui->tabla->setItem(row, 11, new QTableWidgetItem(QString::fromStdString(registro->getProvinciaMuestra())));
        ui->tabla->setItem(row, 12, new QTableWidgetItem(QString::fromStdString(registro->getDistritoMuestra())));
        ui->tabla->setItem(row, 13, new QTableWidgetItem(QString::fromStdString(registro->getTipoMuestra())));
        ui->tabla->setItem(row, 14, new QTableWidgetItem(QString::fromStdString(registro->getResultado())));

    }


}


void Principal::on_Modificar_clicked()
{

    // Obtén el uuid del registro que estás modificando
    int uuid = ui->Luuid->text().toInt();

    // Encuentra el registro en el árbol AVL
    AVLTree* tree = DataHolder::instance().getTree();
    Registro* registro = tree->search(uuid);

    // Si se encontró el registro, actualiza sus datos
    if (registro != nullptr) {
        // Actualiza los atributos del registro directamente en el ARBOL
        registro->setFechaCorte(ui->LfechaCorte->text().toStdString());
        registro->setUuid(ui->Luuid->text().toInt());
        registro->setFechaMuestra(ui->LfechaMuesta->text().toStdString());
        registro->setEdad(ui->Ledad->text().toInt());
        registro->setSexo(ui->Lsexo->text().toStdString());
        registro->setInstitucion(ui->Linstitucion->text().toStdString());
        registro->setUbigeoPaciente(ui->LubigeoPaciente->text().toStdString());
        registro->setDepartamentoPaciente(ui->LdepartamentoPaciente->text().toStdString());
        registro->setProvinciaPaciente(ui->LprovinciaPaciente->text().toStdString());
        registro->setDistritoPaciente(ui->LdistritoPaciente->text().toStdString());
        registro->setDepartamentoMuestra(ui->LdepartamentoMuestra->text().toStdString());
        registro->setProvinciaMuestra(ui->LprovinciaMuestra->text().toStdString());
        registro->setDistritoMuestra(ui->LdistritoMuestra->text().toStdString());
        registro->setTipoMuestra(ui->LtipoMuestra->text().toStdString());
        registro->setResultado(ui->Lresultado->text().toStdString());
        // Actualiza los demás atributos según tus necesidades

        // Ahora, actualiza la fila específica en la que se encuentra el registro modificado en la tabla
        int row = ui->tabla->currentRow();

        if (row >= 0 && row < ui->tabla->rowCount()) {
            //En la tabla
            ui->tabla->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(registro->getFechaCorte())));
            ui->tabla->setItem(row, 1, new QTableWidgetItem(QString::number(registro->getUuid())));
            ui->tabla->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(registro->getFechaMuestra())));
            ui->tabla->setItem(row, 3, new QTableWidgetItem(QString::number(registro->getEdad())));
            ui->tabla->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(registro->getSexo())));
            ui->tabla->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(registro->getInstitucion())));
            ui->tabla->setItem(row, 6, new QTableWidgetItem(QString::fromStdString(registro->getUbigeoPaciente())));
            ui->tabla->setItem(row, 7, new QTableWidgetItem(QString::fromStdString(registro->getDepartamentoPaciente())));
            ui->tabla->setItem(row, 8, new QTableWidgetItem(QString::fromStdString(registro->getProvinciaPaciente())));
            ui->tabla->setItem(row, 9, new QTableWidgetItem(QString::fromStdString(registro->getDistritoPaciente())));
            ui->tabla->setItem(row, 10, new QTableWidgetItem(QString::fromStdString(registro->getDepartamentoMuestra())));
            ui->tabla->setItem(row, 11, new QTableWidgetItem(QString::fromStdString(registro->getProvinciaMuestra())));
            ui->tabla->setItem(row, 12, new QTableWidgetItem(QString::fromStdString(registro->getDistritoMuestra())));
            ui->tabla->setItem(row, 13, new QTableWidgetItem(QString::fromStdString(registro->getTipoMuestra())));
            ui->tabla->setItem(row, 14, new QTableWidgetItem(QString::fromStdString(registro->getResultado())));

        }
    }
}


void Principal::on_tabla_itemClicked(QTableWidgetItem *item)
{
    f= item->row();
    QTableWidgetItem *fechacorte= ui->tabla->item(f,0);
    QTableWidgetItem *uuid= ui->tabla->item(f,1);
    QTableWidgetItem *fechamuestra= ui->tabla->item(f,2);
    QTableWidgetItem *edad= ui->tabla ->item(f,3);
    QTableWidgetItem *Sexo= ui->tabla ->item(f,4);
    QTableWidgetItem *institucion= ui->tabla ->item(f,5);
    QTableWidgetItem *ubigeoPaciente= ui->tabla ->item(f,6);
    QTableWidgetItem *departamentoPaciente= ui->tabla ->item(f,7);
    QTableWidgetItem *provinciaPaciente= ui->tabla ->item(f,8);
    QTableWidgetItem *distritoPaciente= ui->tabla ->item(f,9);
    QTableWidgetItem *departamentoMuestra= ui->tabla ->item(f,10);
    QTableWidgetItem *provinciaMuestra= ui->tabla ->item(f,11);
    QTableWidgetItem *distritoMuestra= ui->tabla ->item(f,12);
    QTableWidgetItem *tipoMuestra= ui->tabla ->item(f,13);
    QTableWidgetItem *resultado= ui->tabla ->item(f,14);


    ui ->LfechaCorte->setText(fechacorte->text());
    ui ->Luuid->setText(uuid->text());
    ui ->LfechaMuesta->setText(fechamuestra->text());
    ui ->Ledad->setText(edad->text());
    ui ->Lsexo->setText(Sexo->text());
    ui ->Linstitucion->setText(institucion->text());
    ui ->LubigeoPaciente->setText(ubigeoPaciente->text());
    ui ->LdepartamentoPaciente->setText(departamentoPaciente->text());
    ui ->LprovinciaPaciente->setText(provinciaPaciente->text());
    ui ->LdistritoPaciente->setText(distritoPaciente->text());
    ui ->LdepartamentoMuestra->setText(departamentoMuestra->text());
    ui ->LprovinciaMuestra->setText(provinciaMuestra->text());
    ui ->LdistritoMuestra->setText(distritoMuestra->text());
    ui ->LtipoMuestra->setText(tipoMuestra->text());
    ui ->Lresultado->setText(resultado->text());
}




