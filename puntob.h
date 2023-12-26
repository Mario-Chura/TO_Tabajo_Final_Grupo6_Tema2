#ifndef PUNTOB_H
#define PUNTOB_H

#include <QMainWindow>

#include "CsvParser.h"
#include "ConteoFiltrado.h"

namespace Ui {
class puntob;
}

class puntob : public QMainWindow
{
    Q_OBJECT

public:
    explicit puntob(QWidget *parent = nullptr);
    ~puntob();

private slots:
    void on_pushButton_clicked();

private:
    Ui::puntob *ui;
};

#endif // PUNTOB_H
