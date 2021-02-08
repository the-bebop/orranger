#include "run.hpp"
#include <QApplication>
#include <backend/reactor/hpp/moderator.hpp>

namespace gui {

int UserInterface::run() {
  printf("IM RdUNNING \n");
  main_window.show();
  return qapp->exec();
}

UserInterface::UserInterface(int argc, char **argv,
                             moderator::Moderator &moderator) {

  printf("IM RUNNING \n");
  printf("IM RUNNINdG \n");
  system_argc = argc;
  system_argv = argv;
  QApplication loc_app(system_argc, system_argv);
  qapp = &loc_app;
  MainWindow main_window;
  main_window.set_event_list(moderator);
}

UserInterface::~UserInterface() {
  qapp->closeAllWindows();
  qapp->quit();
}

} // namespace gui
