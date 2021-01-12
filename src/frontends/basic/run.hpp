#ifndef RUN_HPP
#define RUN_HPP

#include "mainwindow.h"

/**
 * @brief run is the callable that will be executed in an independend thread. It
 is mainly there to run the GUI
 *
 * @param argc forwarded from main execution
 * @param argv forwarded from main execution
 * @param extern_events event communicator
 * @return Qt error code
 */
int run(int argc, char **argv,
        std::vector<events::MainControls> &extern_events);

#endif // RUN_HPP
