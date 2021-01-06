#include <hpp/reactor.hpp>
#include <frontends/default/mainwindow.h>
#include <QMainWindow>
#include <QApplication>

int main(int argc, char *argv[])
{
    reactor::Reactor mission_control;

    mission_control.update();
    
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    return 0;
}