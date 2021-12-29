#include "mainwindow.h"

#include <QApplication>
#include <QProcess>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // set path to external program here
    QString program = "";

    QStringList arguments;
    arguments<<"-p" << "val";

    QProcess *myProcess = new QProcess();

    QProcess::connect(myProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
                      [=](int exitCode, QProcess::ExitStatus exitStatus){
        qDebug()<<exitCode;
        qDebug()<<exitStatus;
        qDebug()<<myProcess->readLine();
    });

    myProcess->start(program, arguments);

    MainWindow w;
    w.show();
    return a.exec();
}
