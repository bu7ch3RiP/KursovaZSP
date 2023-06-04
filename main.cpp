#include "mainwindow.h"
#include <QApplication>
#include <QLabel>

#include <QFile>
#include <QString>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/color/palette/pictures/MonitorTesting.ico"));
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    MainWindow w;
    w.show();
    return a.exec();
}
