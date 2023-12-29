/*#include "estadistica4.h"
#include "ui_estadistica4.h"
#include "principal.h"
#include "DataHolder.h"
#include <iostream>
#include <QFileDialog>
#include <QTextStream>
#include <vector>

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





void Estadistica4::on_carga_clicked()
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

        QString tipoMuestraResultado = campos[10].trimmed();
        QString institucionSexo = campos[13].trimmed() + "_" + campos[14].trimmed();

        if (!conteos.contains(tipoMuestraResultado)) {
            conteos[tipoMuestraResultado] = QMap<QString, int>();
        }

        if (!conteos[tipoMuestraResultado].contains(institucionSexo)) {
            conteos[tipoMuestraResultado][institucionSexo] = 1;
        } else {
            conteos[tipoMuestraResultado][institucionSexo]++;
        }
    }

    // Limpiar la tabla antes de agregar nuevos datos
    ui->tabla->clear();

    // Configurar las columnas en la tabla
    QStringList headerLabels;
    headerLabels << "Tipo Muestra"
                 << "ESSALUD Masculino" << "ESSALUD Femenino"
                 << "Gobierno Regional Masculino" << "Gobierno Regional Femenino"
                 << "Ministerio Defensa Masculino" << "Ministerio Defensa Femenino"
                 << "MS DIRIS Masculino" << "MS DIRIS Femenino"
                 << "MS Instituto Nacional Salud Masculino" << "MS Instituto Nacional Salud Femenino"
                 << "Municipalidades Masculino" << "Municipalidades Femenino"
                 << "Otros Masculino" << "Otros Femenino"
                 << "Privado Masculino" << "Privado Femenino"
                 << "Sanidad Fuerza Aerea Masculino" << "Sanidad Fuerza Aerea Femenino"
                 << "Sanidad Marina Masculino" << "Sanidad Marina Femenino"
                 << "Sanidad Policia Nacional Masculino" << "Sanidad Policia Nacional Femenino"
                 << "Sanidad Ejercito Masculino" << "Sanidad Ejercito Femenino"
                 << "Total";
    ui->tabla->setColumnCount(headerLabels.size());
    ui->tabla->setHorizontalHeaderLabels(headerLabels);

    // Imprimir los resultados de aspirados negativos y positivos por departamento en la tabla
    int row = 0;  // Fila actual en la tabla

    QStringList tiposMuestra = {"ASPIRADO TRAQUEAL_NEGATIVO", "ASPIRADO TRAQUEAL_POSITIVO",
                                "HISOPADO NASAL Y FARINGEO_NEGATIVO", "HISOPADO NASAL Y FARINGEO_POSITIVO",
                                "LAVADO BRONCOALVEOLAR_NEGATIVO", "LAVADO BRONCOALVEOLAR_POSITIVO",
                                "TEJIDO PULMONAR_NEGATIVO", "TEJIDO PULMONAR_POSITIVO"};

    for (const QString& tipoMuestraResultado : tiposMuestra) {
        // Insertar datos en la tabla
        ui->tabla->insertRow(row);
        ui->tabla->setItem(row, 0, new QTableWidgetItem(tipoMuestraResultado));

        // Iterar sobre los departamentos y obtener los conteos
        int col = 1;  // Columna actual en la tabla
        QMapIterator<QString, QMap<QString, int>> it(conteos);
        while (it.hasNext()) {
            it.next();
            QString institucionSexo = it.key();
            int conteo = conteos[tipoMuestraResultado].value(tipoMuestraResultado, 0);
            ui->tabla->setItem(row, col, new QTableWidgetItem(QString::number(conteo)));
            ++col;
        }

        // Calcular y agregar la columna de TOTAL
        int total = std::accumulate(conteos.begin(), conteos.end(), 0,
                                    [tipoMuestraResultado](int acc, const QMap<QString, int>& depConteos) {
                                        return acc + depConteos.value(tipoMuestraResultado, 0);
                                    });
        ui->tabla->setItem(row, col, new QTableWidgetItem(QString::number(total)));

        ++row;
    }
}



    QMapIterator<QString, QMap<QString, int>> it(conteos);
    while (it.hasNext()) {
        it.next();
        QString institucionSexo = it.key();

        int conteoEssaludMasculino = conteos[institucionSexo].value("ESSALUD_MASCULINO", 0);
        int conteoEssaludFemenino = conteos[institucionSexo].value("ESSALUD_FEMENINO", 0);
        int conteoGobiernoMasculino = conteos[institucionSexo].value("GOBIERNO REGIONAL_MASCULINO", 0);
        int conteoGobiernoFemenino = conteos[institucionSexo].value("GOBIERNO REGIONAL_FEMENINO", 0);
        int conteoMinisterioMasculino = conteos[institucionSexo].value("MINISTERIO DE DEFENSA_MASCULINO", 0);
        int conteoMinisterioFemenino = conteos[institucionSexo].value("MINISTERIO DE DEFENSA_FEMENINO", 0);
        int conteoDirisMasculino = conteos[institucionSexo].value("MINISTERIO DE SALUD - DIRIS_MASCULINO", 0);
        int conteoDirisFemenino = conteos[institucionSexo].value("MINISTERIO DE SALUD - DIRIS_FEMENINO", 0);
        int conteoInstitutoMasculino = conteos[institucionSexo].value("MINISTERIO DE SALUD - INSTITUTO NACIONAL DE SALUD_MASCULINO", 0);
        int conteoInstitutoFemenino = conteos[institucionSexo].value("MINISTERIO DE SALUD - INSTITUTO NACIONAL DE SALUD_FEMENINO", 0);
        int conteoMunicipalidadMasculino = conteos[institucionSexo].value("MUNICIPALIDADES_MASCULINO", 0);
        int conteoMunicipalidadFemenino = conteos[institucionSexo].value("MUNICIPALIDADES_FEMENINO", 0);
        int conteoOtrosMasculino = conteos[institucionSexo].value("OTROS_MASCULINO", 0);
        int conteoOtrosFemenino = conteos[institucionSexo].value("OTROS_FEMENINO", 0);
        int conteoPrivadoMasculino = conteos[institucionSexo].value("PRIVADO_MASCULINO", 0);
        int conteoPrivadoFemenino = conteos[institucionSexo].value("PRIVADO_FEMENINO", 0);
        int conteoAereaMasculino = conteos[institucionSexo].value("SANIDAD DE LA FUERZA AEREA DEL PERU_MASCULINO", 0);
        int conteoAereaFemenino = conteos[institucionSexo].value("SANIDAD DE LA FUERZA AEREA DEL PERU_FEMENINO", 0);
        int conteoMarinaMasculino = conteos[institucionSexo].value("SANIDAD DE LA MARINA DE GUERRA DEL PERU_MASCULINO", 0);
        int conteoMarinaFemenino = conteos[institucionSexo].value("SANIDAD DE LA MARINA DE GUERRA DEL PERU_FEMENINO", 0);
        int conteoPoliciaMasculino = conteos[institucionSexo].value("SANIDAD DE LA POLICIA NACIONAL DEL PERU_MASCULINO", 0);
        int conteoPoliciaFemenino = conteos[institucionSexo].value("SANIDAD DE LA POLICIA NACIONAL DEL PERU_FEMENINO", 0);
        int conteoEjercitoMasculino = conteos[institucionSexo].value("SANIDAD DEL EJERCITO DEL PERU_MASCULINO", 0);
        int conteoEjercitoFemenino = conteos[institucionSexo].value("SANIDAD DEL EJERCITO DEL PERU_FEMENINO", 0);
        int total = conteoEssaludMasculino + conteoEssaludFemenino +
                    conteoGobiernoMasculino + conteoGobiernoFemenino +
                    conteoMinisterioMasculino + conteoMinisterioFemenino +
                    conteoDirisMasculino + conteoDirisFemenino +
                    conteoInstitutoMasculino + conteoInstitutoFemenino +
                    conteoMunicipalidadMasculino + conteoMunicipalidadFemenino +
                    conteoOtrosMasculino + conteoOtrosFemenino +
                    conteoPrivadoMasculino + conteoPrivadoFemenino +
                    conteoAereaMasculino + conteoAereaFemenino +
                    conteoMarinaMasculino + conteoMarinaFemenino +
                    conteoPoliciaMasculino + conteoPoliciaFemenino +
                    conteoEjercitoMasculino + conteoEjercitoFemenino;

        // Insertar datos en la tabla
        ui->tabla->insertRow(row);
        ui->tabla->setItem(row, 0, new QTableWidgetItem(institucionSexo));
        ui->tabla->setItem(row, 1, new QTableWidgetItem(QString::number(conteoEssaludMasculino)));
        ui->tabla->setItem(row, 2, new QTableWidgetItem(QString::number(conteoEssaludFemenino)));
        ui->tabla->setItem(row, 3, new QTableWidgetItem(QString::number(conteoGobiernoMasculino)));
        ui->tabla->setItem(row, 4, new QTableWidgetItem(QString::number(conteoGobiernoFemenino)));
        ui->tabla->setItem(row, 5, new QTableWidgetItem(QString::number(conteoMinisterioMasculino)));
        ui->tabla->setItem(row, 6, new QTableWidgetItem(QString::number(conteoMinisterioFemenino)));
        ui->tabla->setItem(row, 7, new QTableWidgetItem(QString::number(conteoDirisMasculino)));
        ui->tabla->setItem(row, 8, new QTableWidgetItem(QString::number(conteoDirisFemenino)));
        ui->tabla->setItem(row, 9, new QTableWidgetItem(QString::number(conteoInstitutoMasculino)));
        ui->tabla->setItem(row, 10, new QTableWidgetItem(QString::number(conteoInstitutoFemenino)));
        ui->tabla->setItem(row, 11, new QTableWidgetItem(QString::number(conteoMunicipalidadMasculino)));
        ui->tabla->setItem(row, 12, new QTableWidgetItem(QString::number(conteoMunicipalidadFemenino)));
        ui->tabla->setItem(row, 13, new QTableWidgetItem(QString::number(conteoOtrosMasculino)));
        ui->tabla->setItem(row, 14, new QTableWidgetItem(QString::number(conteoOtrosFemenino)));
        ui->tabla->setItem(row, 15, new QTableWidgetItem(QString::number(conteoPrivadoMasculino)));
        ui->tabla->setItem(row, 16, new QTableWidgetItem(QString::number(conteoPrivadoFemenino)));
        ui->tabla->setItem(row, 17, new QTableWidgetItem(QString::number(conteoAereaMasculino)));
        ui->tabla->setItem(row, 18, new QTableWidgetItem(QString::number(conteoAereaFemenino)));
        ui->tabla->setItem(row, 19, new QTableWidgetItem(QString::number(conteoMarinaMasculino)));
        ui->tabla->setItem(row, 20, new QTableWidgetItem(QString::number(conteoMarinaFemenino)));
        ui->tabla->setItem(row, 21, new QTableWidgetItem(QString::number(conteoPoliciaMasculino)));
        ui->tabla->setItem(row, 22, new QTableWidgetItem(QString::number(conteoPoliciaFemenino)));
        ui->tabla->setItem(row, 23, new QTableWidgetItem(QString::number(conteoEjercitoMasculino)));
        ui->tabla->setItem(row, 24, new QTableWidgetItem(QString::number(conteoEjercitoFemenino)));
        ui->tabla->setItem(row, 25, new QTableWidgetItem(QString::number(total)));

        ++row;
    }

}

void Estadistica4::on_reporte_clicked()
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
*/

#include "estadistica4.h"
#include "e4conteofiltrado.h"
#include "e4csvprsr.h"
#include "ui_estadistica4.h"
#include "principal.h"
#include "DataHolder.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>

Estadistica4::Estadistica4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Estadistica4)
{
    ui->setupUi(this);
    ;
}

Estadistica4::~Estadistica4()
{
    delete ui;
}

void Estadistica4::exportarCSV() {
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


void Estadistica4::on_menu_clicked()
{
    // Oculta la ventana actual (MainPage)
    this->hide();

    // Crea o obtén la instancia de la ventana llamada "principal"
    Principal *principal = new Principal();  // Asegúrate de que la clase se llama "Principal"

    // Muestra la ventana "principal"
    principal->show();
}


void Estadistica4::on_carga_clicked()
{

    // Nombre de la ruta donde está el archivo CSV
    QString nombreArchivo = DataHolder::instance().getNombreArchivo();
    QString rutaArchivoCSV = nombreArchivo;

    // Leer el archivo CSV
    std::vector<e4paciente> dataVector = e4csvprsr::parseCsv(rutaArchivoCSV.toStdString());

    // En algún lugar de tu código donde desees utilizar la función ConteoFiltrado::realizarConteo
    e4conteofiltrado conteoFiltrado;

    // Asegúrate de tener tus datos aquí
    std::vector<QStringList> result = conteoFiltrado.realizarConteo(dataVector);

    // Limpiar la tabla antes de agregar nuevos datos
    ui->tabla->clear();

    // Configurar las columnas en la tabla
    QStringList headerLabels;
    headerLabels << "Institucion" << "Sexo" << "Tipo Muestra" << "Resultado" << "Total";
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


void Estadistica4::on_reporte_clicked()
{
    exportarCSV();
}

