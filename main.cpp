#include "mainwindow.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/color/palette/pictures/MonitorTesting.ico"));
    MainWindow w;
    w.show();
    return a.exec();
}
