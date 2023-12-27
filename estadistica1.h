#ifndef ESTADISTICA1_H
#define ESTADISTICA1_H

#include <QMainWindow>

namespace Ui {
class Estadistica1;
}

class Estadistica1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Estadistica1(QWidget *parent = nullptr);
    ~Estadistica1();

private slots:
    void on_menu_clicked();

private:
    Ui::Estadistica1 *ui;
};

#endif // ESTADISTICA1_H
