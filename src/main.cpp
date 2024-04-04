#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
    m3mpm::Calculator m;
    m3mpm::Credit c;
    m3mpm::Deposit d;
    m3mpm::Controller controller(&m, &c, &d);
    QApplication a(argc, argv);
    MainWindow w(&controller);
    w.show();
    return a.exec();
}
