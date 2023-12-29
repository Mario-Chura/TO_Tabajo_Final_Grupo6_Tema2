#ifndef ESTADISTICA2_H
#define ESTADISTICA2_H

#include <QMainWindow>

namespace Ui {
class Estadistica2;
}

class Estadistica2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Estadistica2(QWidget *parent = nullptr);
    ~Estadistica2();

private slots:
    void on_menu_clicked();

private:
    Ui::Estadistica2 *ui;
};

#endif // ESTADISTICA2_H
