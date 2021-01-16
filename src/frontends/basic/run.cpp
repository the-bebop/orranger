#include "run.hpp"
#include <QApplication>
#include <backend/reactor/hpp/moderator.hpp>

int run(int argc, char **argv, moderator::Moderator &moderator) {
  QApplication a(argc, argv);
  MainWindow w;
  w.set_event_list(moderator);
  w.show();
  return a.exec();
}
