#include "../common/gui_events.hpp"
#include "mainwindow.h"
#include "run.hpp"
#include <QApplication>

/**
 * @brief this main is only required for gui standalone build
 *
 * @param argc forwarded from main execution
 * @param argv forwarded from main execution
 * @return Qt error code
 */
int main(int argc, char *argv[]) {
  std::vector<events::MainControls> events;
  run(argc, argv, events);
}
