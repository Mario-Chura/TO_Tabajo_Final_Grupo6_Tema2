#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "AVLTree.h"
#include <QMainWindow>
#include "qtablewidget.h"




namespace Ui {
class Principal;
}

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Principal(AVLTree* tree, QWidget *parent = nullptr);
    explicit Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:


    void on_estadistica1_clicked();

    void on_estadistica2_clicked();

    void on_estadistica3_clicked();

    void on_estadistica4_clicked();

    void on_CargaRegistro_clicked();

    void on_Modificar_clicked();

    void on_tabla_itemClicked(QTableWidgetItem *item);

private:
    Ui::Principal *ui;
    AVLTree* tree;
    int f;
};

#endif // PRINCIPAL_H
