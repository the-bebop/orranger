#ifndef RUN_HPP
#define RUN_HPP

#include "mainwindow.h"
#include <backend/reactor/hpp/moderator.hpp>

/**
 * @brief run is the callable that will be executed in an independend thread. It
 is mainly there to run the GUI
 *
 * @param argc forwarded from main execution
 * @param argv forwarded from main execution
 * @param moderator event communicator
 * @return Qt error code
 */
int run(int argc, char **argv, moderator::Moderator &moderator);

#endif // RUN_HPP
