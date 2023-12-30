#ifndef REGISTROUSUARIO_H
#define REGISTROUSUARIO_H

#include <QMainWindow>

namespace Ui {
class Registrousuario;
}

class Registrousuario : public QMainWindow
{
    Q_OBJECT

public:
    explicit Registrousuario(QWidget *parent = nullptr);
    ~Registrousuario();

private:
    Ui::Registrousuario *ui;
};

#endif // REGISTROUSUARIO_H
