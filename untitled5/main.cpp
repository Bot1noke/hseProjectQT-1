#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.setWindowTitle("NBA Enjoyer");
    window.resize(1200, 1080);
    window.show();
    return a.exec();
}
