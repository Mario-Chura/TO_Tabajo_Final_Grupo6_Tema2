#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

namespace Ui {
class Principal;
}

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_CargaEncabezado_clicked();

    void on_estadistica1_clicked();

    void on_estadistica2_clicked();

    void on_estadistica3_clicked();

    void on_estadistica4_clicked();

private:
    Ui::Principal *ui;
};

#endif // PRINCIPAL_H
