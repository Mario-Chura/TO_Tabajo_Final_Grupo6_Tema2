#include "mainwindow.h"


#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <vector>
#include <iostream>
#include <map>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}





