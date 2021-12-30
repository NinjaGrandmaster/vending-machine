#include "widget.h"

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

    myProcess->start(program, arguments);

    myProcess->waitForReadyRead();
    myProcess->write("-p");
    QByteArray progamOutput = myProcess->readAllStandardOutput();

    qDebug()<< "Test --- : " << progamOutput;


    Widget w;
    w.show();
    return a.exec();
}
