#ifndef Estadistica4_H
#define Estadistica4_H
#include <QMainWindow>
#include <map>
#include <iostream>
#include <vector>
#include "e4paciente.h"
#include <QTextDocument>
#include <QPdfWriter>
#include <QFile>
#include <QTextStream>
#include <QPainter>
#include <QMessageBox>
#include <QStringList>


namespace Ui {
class Estadistica4;
}

class Estadistica4 : public QMainWindow
{
    Q_OBJECT

public:
    static void realizarConteo(const std::vector<e4paciente>& dataVector);
    explicit Estadistica4(QWidget *parent = nullptr);

    ~Estadistica4();
    void exportarCSV();
private slots:
    void on_menu_clicked();

    void on_carga_clicked();

    void on_reporte_clicked();

private:
    Ui::Estadistica4 *ui;

    QMap<QString, QMap<QString, int>> conteos;
};

#endif // Estadistica2_H
