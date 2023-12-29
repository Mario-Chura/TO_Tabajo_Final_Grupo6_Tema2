#include "estadistica3.h"
#include "ui_estadistica3.h"
#include "principal.h"
#include "DataHolder.h"
#include <iostream>

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





void Estadistica3::on_carga_clicked()
{
    const std::vector<std::vector<Registro*>>& departamentoMuestras = DataHolder::instance().getDepartamentoMuestras();

    // Declaras un vector para almacenar los nombres de departamentos
    std::vector<std::string> nombresDepartamentos;

    // Agregamos "Tipo de muestra" al principio del vector
    nombresDepartamentos.push_back("Tipo de muestra");

    // Iteras sobre departamentoMuestras para obtener los nombres y almacenarlos en el nuevo vector
    for (const auto& vec : departamentoMuestras) {
        if (!vec.empty()) {  // Asegúrate de que el vector interno no esté vacío
            nombresDepartamentos.push_back(vec[0]->getDepartamentoMuestra());
        }
    }

    // Agregamos "Total General" al final del vector
    nombresDepartamentos.push_back("Total General");

    // Verificamos que haya nombres de departamentos antes de intentar configurar la tabla
    if (!nombresDepartamentos.empty()) {
        // Establecemos el encabezado de la tabla con el vector de nombres de departamentos
        ui->tabla->setColumnCount(nombresDepartamentos.size());
        ui->tabla->setRowCount(2);  // Configuramos dos filas

        // Configuramos el encabezado
        for (int i = 0; i < nombresDepartamentos.size(); ++i) {
            QTableWidgetItem *headerItem = new QTableWidgetItem(QString::fromStdString(nombresDepartamentos[i]));
            ui->tabla->setHorizontalHeaderItem(i, headerItem);
            ui->tabla->setColumnWidth(i, 200);  // Puedes ajustar el ancho según tus necesidades
        }

        // Agregamos una segunda fila con todos los contenidos positivos
        for (int i = 0; i < nombresDepartamentos.size(); ++i) {
            QTableWidgetItem *item = new QTableWidgetItem("1");  // Puedes ajustar el valor según tus necesidades
            ui->tabla->setItem(0, i, item);
        }
    } else {
        std::cerr << "No hay nombres de departamentos disponibles." << std::endl;
    }


    QString nombreArchivo = DataHolder::instance().getNombreArchivo();
    std::cout << nombreArchivo.toStdString() << std::endl;
}

