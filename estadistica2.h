#ifndef Estadistica2_H
#define Estadistica2_H
#include <QMainWindow>
#include <map>
#include <iostream>
#include <vector>
#include "e2paciente.h"
#include <QTextDocument>
#include <QPdfWriter>
#include <QFile>
#include <QTextStream>
#include <QPainter>
#include <QMessageBox>
#include <QStringList>


namespace Ui {
class Estadistica2;
}

class Estadistica2 : public QMainWindow
{
    Q_OBJECT

public:
    static void realizarConteo(const std::vector<e2paciente>& dataVector);
    explicit Estadistica2(QWidget *parent = nullptr);

    ~Estadistica2();
   void exportarCSV();
private slots:
    void on_menu_clicked();

    void on_carga_clicked();

    void on_reporte_clicked();

private:
    Ui::Estadistica2 *ui;

    QMap<QString, QMap<QString, int>> conteos;
};

#endif // Estadistica2_H
