#ifndef RUN_HPP
#define RUN_HPP

#include "mainwindow.h"
#include <QApplication>
#include <backend/reactor/hpp/moderator.hpp>

namespace gui {

class UserInterface {
private:
  QApplication *qapp;
  MainWindow main_window;
  int system_argc;
  char **system_argv;

public:
  UserInterface(int argc, char **argv, moderator::Moderator &moderator);
  ~UserInterface();

  /**
   * @brief run is the callable that will be executed in an independend
   thread. It is mainly there to run the GUI
   *
   * @param argc forwarded from main execution
   * @param argv forwarded from main execution
   * @param moderator event communicator
   * @return Qt error code
   */
  int run();
};
} // namespace gui
#endif // RUN_HPP
