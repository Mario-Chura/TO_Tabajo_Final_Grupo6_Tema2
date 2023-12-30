#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainpage.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Login_clicked()
{
    QString UserName =ui->lineEdit_User_Name->text();
    QString Password =ui->lineEdit_Password->text();

    if ((UserName == "Mario" && Password == "marioch")||
        (UserName == "diego" && Password == "diego") ||
        (UserName == "angie" && Password == "angie") ||
        (UserName == "jhoer" && Password == "jhoer") )
    {
        QMessageBox::information(this, "Mensaje", "Acceso exitoso.");
        this->hide();
        MainPage *mainpage = new MainPage();
        mainpage ->show();
    }
    else
    {
        QMessageBox::warning(this, "Mensaje", "Por favor ingrese un nombre de usuario o contraseña válidos");
    }
}


void MainWindow::on_pushButton_Cancel_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Mensaje", "¿Estás seguro de cerrar la aplicación?",QMessageBox::Yes| QMessageBox:: No);
    if (reply == QMessageBox::Yes){
        QApplication::quit();
    }
}

