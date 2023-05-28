#include "mainwindow.h"
#include<iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int m=3,n=3;

    if ((n % 2 == 0 && m % 2 != 0) || (n % 2 != 0 && m % 2 == 0) || (n == 1 && m == 1) || n <= 0 || m <= 0)
    { qDebug( "can't cover"); }
    else{
        MainWindow w(m,n);
        w.show(); return a.exec();}

}
