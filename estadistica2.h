#ifndef ESTADISTICA2_H
#define ESTADISTICA2_H

#include "AVLTree.h"
#include <QMainWindow>
#include <vector>

namespace Ui {
class Estadistica2;
}

class Estadistica2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Estadistica2(AVLTree* tree, QWidget *parent = nullptr);
    explicit Estadistica2(std::vector<std::vector<Registro*>>* DEPARTAMENTO_MUESTRAS, QWidget *parent = nullptr);
    explicit Estadistica2(QWidget *parent = nullptr);
    ~Estadistica2();

private slots:
    void on_menu_clicked();

    void on_carga_clicked();

private:
    Ui::Estadistica2 *ui;
    std::vector<std::vector<Registro*>>* DEPARTAMENTO_MUESTRAS; // Almacena el puntero al vector
};
#endif // ESTADISTICA2_H
