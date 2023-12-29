#ifndef MAINPAGE_H
#define MAINPAGE_H
#include "AVLTree.h"
#include <QMainWindow>

namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();

signals:
    void arbolCreado(AVLTree* tree);
    void DEPARTAMENTO_MUESTRASCreados(const std::vector<std::vector<Registro*>>& DEPARTAMENTO_MUESTRAS);


private slots:
    void on_carga_clicked();

    void on_siguiente_clicked();

private:
    Ui::MainPage *ui;
};

#endif // MAINPAGE_H
