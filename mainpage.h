#ifndef MAINPAGE_H
#define MAINPAGE_H

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

private slots:
    void on_carga_clicked();

    void on_siguiente_clicked();

private:
    Ui::MainPage *ui;
};

#endif // MAINPAGE_H
