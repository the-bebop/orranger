#include "run.hpp"
#include <QApplication>

int run(int argc, char **argv, std::vector<events::MainControls>& extern_events)
{
    QApplication a(argc, argv);
    MainWindow w;
    w.set_event_list(extern_events);
    w.show();
    return a.exec();
}
