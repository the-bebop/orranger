#include <QApplication>
#include <QMainWindow>
#include <frontends/basic/mainwindow.h>
#include <hpp/reactor.hpp>
#include <iostream>

/**
 * @brief This is the common's program main / entry point
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[]) {
  reactor::Reactor mission_control(argc, argv);

  bool run_orranger = true;

  while (run_orranger)
    run_orranger = mission_control.update();

  std::cout << "[main] reached end by intention " << std::endl;

  return 0;
}