#ifndef ESTADISTICA1_H
#define ESTADISTICA1_H
#include "AVLTree.h"
#include <QMainWindow>
#include <vector>
#include <QDebug>

namespace Ui {
class Estadistica1;
}

class Estadistica1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Estadistica1(AVLTree* tree, QWidget *parent = nullptr);
    explicit Estadistica1(std::vector<std::vector<Registro*>>* DEPARTAMENTO_MUESTRAS, QWidget *parent = nullptr);
    explicit Estadistica1(QWidget *parent = nullptr);
    ~Estadistica1();

private slots:
    void on_menu_clicked();

    void on_carga_clicked();

    void on_reporte_clicked();

private:
    Ui::Estadistica1 *ui;
    std::vector<std::vector<Registro*>>* DEPARTAMENTO_MUESTRAS; // Almacena el puntero al vector
    QMap<QString, QMap<QString, int>> conteos;
};

#endif // ESTADISTICA1_H
