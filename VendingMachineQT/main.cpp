#include "mainwindow.h"

#include <QApplication>
#include <QProcess>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    /*
    MainWindow w;
    w.show();
    */

    //location of program to be run
    QString program = "";


    return a.exec();
}
