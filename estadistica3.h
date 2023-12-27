#ifndef ESTADISTICA3_H
#define ESTADISTICA3_H

#include <QMainWindow>

namespace Ui {
class Estadistica3;
}

class Estadistica3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Estadistica3(QWidget *parent = nullptr);
    ~Estadistica3();

private slots:
    void on_menu_clicked();

private:
    Ui::Estadistica3 *ui;
};

#endif // ESTADISTICA3_H
