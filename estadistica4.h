#ifndef ESTADISTICA4_H
#define ESTADISTICA4_H

#include <QMainWindow>

namespace Ui {
class Estadistica4;
}

class Estadistica4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Estadistica4(QWidget *parent = nullptr);
    ~Estadistica4();

private slots:
    void on_menu_clicked();

private:
    Ui::Estadistica4 *ui;
};

#endif // ESTADISTICA4_H
