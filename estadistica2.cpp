#include "estadistica2.h"
#include "e2conteofiltrado.h"
#include "e2csvprsr.h"
#include "ui_estadistica2.h"
#include "principal.h"
#include "DataHolder.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <iostream>

Estadistica2::Estadistica2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Estadistica2)
{
    ui->setupUi(this);
;
}

Estadistica2::~Estadistica2()
{
    delete ui;
}

void Estadistica2::exportarCSV() {
    QString filePath = QFileDialog::getSaveFileName(this, "Guardar reporte como CSV", QString(), "Archivos CSV (*.csv)");

    if (filePath.isEmpty()) {
        // El usuario canceló la operación
        return;
    }

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);

        // Escribir encabezados
        QStringList header;
        for (int col = 0; col < ui->tabla->columnCount(); ++col) {
            header << ui->tabla->horizontalHeaderItem(col)->text();
        }
        stream << header.join(',') << '\n';

        // Escribir datos
        for (int row = 0; row < ui->tabla->rowCount(); ++row) {
            QStringList rowData;
            for (int col = 0; col < ui->tabla->columnCount(); ++col) {
                QTableWidgetItem *item = ui->tabla->item(row, col);
                if (item) {
                    rowData << item->text();
                } else {
                    rowData << "";  // Si la celda está vacía, agregar un espacio en blanco
                }
            }
            stream << rowData.join(',') << '\n';
        }

        file.close();
        QMessageBox::information(nullptr, "Exportación a CSV", "Los datos se han exportado exitosamente a: " + filePath);
    } else {
        QMessageBox::critical(nullptr, "Error", "No se pudo abrir el archivo para escribir el CSV.");
    }
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


void Estadistica2::on_carga_clicked()
{

    // Nombre de la ruta donde está el archivo CSV
    QString nombreArchivo = DataHolder::instance().getNombreArchivo();
    QString rutaArchivoCSV = nombreArchivo;

    // Leer el archivo CSV
    std::vector<e2paciente> dataVector = e2csvprsr::parseCsv(rutaArchivoCSV.toStdString());

    // En algún lugar de tu código donde desees utilizar la función ConteoFiltrado::realizarConteo
    e2conteofiltrado conteoFiltrado;

      // Asegúrate de tener tus datos aquí
    std::vector<QStringList> result = conteoFiltrado.realizarConteo(dataVector);

    // Limpiar la tabla antes de agregar nuevos datos
    ui->tabla->clear();

    // Configurar las columnas en la tabla
    QStringList headerLabels;
    headerLabels << "Departamento" << "Provincia" << "Sexo" << "Tipo Muestra" << "Resultado" << "Cantidad";
    ui->tabla->setColumnCount(headerLabels.size());
    ui->tabla->setHorizontalHeaderLabels(headerLabels);

    // Llenar la tabla con los datos obtenidos
    for (const QStringList &rowData : result) {
        int row = ui->tabla->rowCount();
        ui->tabla->insertRow(row);
        for (int col = 0; col < rowData.size(); ++col) {
            ui->tabla->setItem(row, col, new QTableWidgetItem(rowData[col]));
        }
    }


}


void Estadistica2::on_reporte_clicked()
{
  exportarCSV();
}

