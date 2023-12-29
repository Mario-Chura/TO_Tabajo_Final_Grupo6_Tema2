#ifndef ESTADISTICA3_H
#define ESTADISTICA3_H
#include "AVLTree.h"
#include <QMainWindow>
#include <vector>
#include <QDebug>
namespace Ui {
class Estadistica3;
}

class Estadistica3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Estadistica3(AVLTree* tree, QWidget *parent = nullptr);
    explicit Estadistica3(std::vector<std::vector<Registro*>>* DEPARTAMENTO_MUESTRAS, QWidget *parent = nullptr);
    explicit Estadistica3(QWidget *parent = nullptr);
    ~Estadistica3();

private slots:
    void on_menu_clicked();

    void on_carga_clicked();

    void on_reporte_clicked();

private:
    Ui::Estadistica3 *ui;
    std::vector<std::vector<Registro*>>* DEPARTAMENTO_MUESTRAS; // Almacena el puntero al vector
    QMap<QString, QMap<QString, int>> conteos;
};

#endif // ESTADISTICA3_H
