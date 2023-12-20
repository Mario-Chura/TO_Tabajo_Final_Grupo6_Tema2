#include "mainwindow.h"
#include "Registro.h"
#include "AVLTree.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <vector>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    AVLTree* tree = new AVLTree();
    std::vector<int> positivos;
    std::vector<int> negativos;

    QFile file("PRUEBAS_COVID_CSV.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return 1;
    }

    // Saltar la línea de encabezado
    file.readLine();

    int id = 1;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        QStringList fields = QString(line).split(";");

        Registro* registro = new Registro(id, fields[0].toStdString(), fields[1].toStdString(), fields[2].toStdString(), fields[3].toInt(), fields[4].toStdString(), fields[5].toStdString(), fields[6].toStdString(), fields[7].toStdString(), fields[8].toStdString(), fields[9].toStdString(), fields[10].toStdString(), fields[11].toStdString(), fields[12].toStdString(), fields[13].toStdString(), fields[14].toStdString());
        tree->insert(registro);

        if (fields[14].toStdString() == "POSITIVO\r\n") {
            positivos.push_back(id);

        } else if (fields[14].toStdString() == "NEGATIVO\r\n") {
            negativos.push_back(id);
        }

        id++;
    }

    // Prueba de búsqueda
    int idBusqueda = 1; // Cambia esto por el ID que quieras buscar
    Registro* registroBuscado = tree->search(idBusqueda);
    if (registroBuscado != nullptr) {
        qDebug() << "Departamento del paciente con ID" << idBusqueda << ":" << QString::fromStdString(registroBuscado->getTipoMuestra());
    } else {
        qDebug() << "No se encontró un registro con el ID" << idBusqueda;
    }

    // Imprimir todos los IDs positivos
    std::cout << "IDs de registros positivos:" << std::endl;
    for (std::vector<int>::size_type i = 0; i < positivos.size(); i++) {
        std::cout << positivos[i] <<" ";
    }

    return a.exec();
}




