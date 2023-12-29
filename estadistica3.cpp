#include "estadistica3.h"
#include "ui_estadistica3.h"
#include "principal.h"
#include "DataHolder.h"
#include <iostream>
#include <QFileDialog>
#include <QTextStream>
#include <vector>

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
    // Nombre de la ruta donde está el archivo CSV
    QString nombreArchivo = DataHolder::instance().getNombreArchivo();
    QString rutaArchivoCSV = nombreArchivo;
    QStringList datos;
    QMap<QString, QMap<QString, int>> conteos;

    // Leer el archivo CSV
    QFile archivo(rutaArchivoCSV);

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error al abrir el archivo";
        return;
    }

    QTextStream stream(&archivo);
    while (!stream.atEnd()) {
        QString linea = stream.readLine();
        datos.append(linea);
    }

    archivo.close();

    // Procesar los datos
    for (const QString& linea : datos) {
        QStringList campos = linea.split(';');

        QString departamento = campos[10].trimmed();
        QString tipoMuestraResultado = campos[13].trimmed() + "_" + campos[14].trimmed();

        if (!conteos.contains(departamento)) {
            conteos[departamento] = QMap<QString, int>();
        }

        if (!conteos[departamento].contains(tipoMuestraResultado)) {
            conteos[departamento][tipoMuestraResultado] = 1;
        } else {
            conteos[departamento][tipoMuestraResultado]++;
        }
    }

    // Limpiar la tabla antes de agregar nuevos datos
    ui->tabla->clear();

    // Configurar las columnas en la tabla
    QStringList headerLabels;
    headerLabels << "Departamento"
                 << "Aspirado Traqueal Negativo" << "Aspirado Traqueal Positivo"
                 << "Hisopado N. Negativo" << "Hisopado N. Positivo"
                 << "Lavado Bronco. Negativo" << "Lavado Bronco. Positivo"
                 << "Tejido Pul. Negativo" << "Tejido Pul. Positivo"
                 << "Total";
    ui->tabla->setColumnCount(headerLabels.size());
    ui->tabla->setHorizontalHeaderLabels(headerLabels);

    // Imprimir los resultados de aspirados negativos y positivos por departamento en la tabla
    int row = 0;  // Fila actual en la tabla
    QMapIterator<QString, QMap<QString, int>> it(conteos);
    while (it.hasNext()) {
        it.next();
        QString departamento = it.key();

        int conteoAspiradoNegativo = conteos[departamento].value("ASPIRADO TRAQUEAL_NEGATIVO", 0);
        int conteoAspiradoPositivo = conteos[departamento].value("ASPIRADO TRAQUEAL_POSITIVO", 0);
        int conteoHisopadoNegativo = conteos[departamento].value("HISOPADO NASAL Y FARINGEO_NEGATIVO", 0);
        int conteoHisopadoPositivo = conteos[departamento].value("HISOPADO NASAL Y FARINGEO_POSITIVO", 0);
        int conteoLavadoNegativo = conteos[departamento].value("LAVADO BRONCOALVEOLAR_NEGATIVO", 0);
        int conteoLavadoPositivo = conteos[departamento].value("LAVADO BRONCOALVEOLAR_POSITIVO", 0);
        int conteoTejidoNegativo = conteos[departamento].value("TEJIDO PULMONAR_NEGATIVO", 0);
        int conteoTejidoPositivo = conteos[departamento].value("TEJIDO PULMONAR_POSITIVO", 0);
        int total = conteoAspiradoNegativo + conteoAspiradoPositivo +
                    conteoHisopadoNegativo + conteoHisopadoPositivo +
                    conteoLavadoNegativo + conteoLavadoPositivo +
                    conteoTejidoNegativo + conteoTejidoPositivo;

        // Insertar datos en la tabla
        ui->tabla->insertRow(row);
        ui->tabla->setItem(row, 0, new QTableWidgetItem(departamento));
        ui->tabla->setItem(row, 1, new QTableWidgetItem(QString::number(conteoAspiradoNegativo)));
        ui->tabla->setItem(row, 2, new QTableWidgetItem(QString::number(conteoAspiradoPositivo)));
        ui->tabla->setItem(row, 3, new QTableWidgetItem(QString::number(conteoHisopadoNegativo)));
        ui->tabla->setItem(row, 4, new QTableWidgetItem(QString::number(conteoHisopadoPositivo)));
        ui->tabla->setItem(row, 5, new QTableWidgetItem(QString::number(conteoLavadoNegativo)));
        ui->tabla->setItem(row, 6, new QTableWidgetItem(QString::number(conteoLavadoPositivo)));
        ui->tabla->setItem(row, 7, new QTableWidgetItem(QString::number(conteoTejidoNegativo)));
        ui->tabla->setItem(row, 8, new QTableWidgetItem(QString::number(conteoTejidoPositivo)));
        ui->tabla->setItem(row, 9, new QTableWidgetItem(QString::number(total)));

        ++row;
    }

}


void Estadistica3::on_reporte_clicked()
{
    // Abrir un cuadro de diálogo para seleccionar la ubicación del archivo CSV
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
        qDebug() << "Reporte exportado exitosamente a: " << filePath;
    } else {
        qDebug() << "Error al abrir el archivo para escribir.";
    }
}

