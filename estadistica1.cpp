#include "estadistica1.h"
#include "ui_estadistica1.h"
#include "principal.h"
#include "DataHolder.h"
#include <iostream>
#include <QFileDialog>
#include <QTextStream>
#include <vector>
#include <QDebug>

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


void Estadistica1::on_carga_clicked()
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
       headerLabels << "Tipo Muestra"
                    << "ANCASH" << "APURIMAC"
                    << "AREQUIPA" << "AYACUCHO"
                    << "CAJAMARCA" << "CALLAO"
                    << "CUSCO" << "DEPARTAMENTO_MUESTRA"
                    << "HUANCAVELICA"
                    << "HUANUCO" << "ICA"
                    << "JUNIN" << "LA LIBERTAD"
                    << "LAMBAYEQUE" << "LIMA"
                    << "LORETO" << "MADRE DE DIOS"
                    << "PASCO" << "PIURA"
                    << "SAN MARTIN" << "TUMBES"
                    << "TOTAL";
       ui->tabla->setColumnCount(headerLabels.size());
       ui->tabla->setHorizontalHeaderLabels(headerLabels);

       // Imprimir los resultados en la tabla
       int row = 0;  // Fila actual en la tabla

       // Iterar sobre los tipos de muestra
       QStringList tiposMuestra = {"ASPIRADO TRAQUEAL_NEGATIVO", "ASPIRADO TRAQUEAL_POSITIVO",
                                   "HISOPADO NASAL Y FARINGEO_NEGATIVO", "HISOPADO NASAL Y FARINGEO_POSITIVO",
                                   "LAVADO BRONCOALVEOLAR_NEGATIVO", "LAVADO BRONCOALVEOLAR_POSITIVO",
                                   "TEJIDO PULMONAR_NEGATIVO", "TEJIDO PULMONAR_POSITIVO"};

       for (const QString& tipoMuestra : tiposMuestra) {
           // Insertar datos en la tabla
           ui->tabla->insertRow(row);
           ui->tabla->setItem(row, 0, new QTableWidgetItem(tipoMuestra));

           // Iterar sobre los departamentos y obtener los conteos
           int col = 1;  // Columna actual en la tabla
           QMapIterator<QString, QMap<QString, int>> it(conteos);
           while (it.hasNext()) {
               it.next();
               QString departamento = it.key();
               int conteo = conteos[departamento].value(tipoMuestra, 0);
               ui->tabla->setItem(row, col, new QTableWidgetItem(QString::number(conteo)));
               ++col;
           }

           // Calcular y agregar la columna de TOTAL
           int total = std::accumulate(conteos.begin(), conteos.end(), 0,
                                       [tipoMuestra](int acc, const QMap<QString, int>& depConteos) {
                                           return acc + depConteos.value(tipoMuestra, 0);
                                       });
           ui->tabla->setItem(row, col, new QTableWidgetItem(QString::number(total)));

           ++row;
       }
   }



void Estadistica1::on_reporte_clicked()
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



