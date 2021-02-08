#include <algorithm>
#include <frontends/basic/run.hpp>
#include <hpp/reactor.hpp>
#include <iostream>

namespace reactor {

bool Reactor::update() {
  bool quitter = true;
  std::vector<events::MainControls> current_events;
  moderator.get_events(current_events);
  for (auto &event : current_events) {
    printf("%i \n", event);
    switch (event) {
    case events::QUIT:

      quitter = false;
      break;
    }
  }

  return quitter;
}

Reactor::Reactor(int argc, char **argv) {
  printf("ALRIGHT\n");
  gui::UserInterface gui = gui::UserInterface(argc, argv, moderator);
  printf("YIPP\n");
  std::thread gui_thread(&gui::UserInterface::run, &gui);
  printf("GO\n");
  threads.push_back(std::move(gui_thread));

  for (auto &thread : threads)
    thread.detach();
}

} // end namespace reactor