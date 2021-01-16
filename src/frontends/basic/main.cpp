
#include "mainwindow.h"
#include "run.hpp"
#include <QApplication>
#include <backend/reactor/hpp/moderator.hpp>
#include <frontends/common/gui_events.hpp>

/**
 * @brief this main is only required for gui standalone build
 *
 * @param argc forwarded from main execution
 * @param argv forwarded from main execution
 * @return Qt error code
 */
int main(int argc, char *argv[]) {
  moderator::Moderator events;
  run(argc, argv, events);
}
