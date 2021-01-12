#include <algorithm>
#include <frontends/basic/run.hpp>
#include <hpp/reactor.hpp>
#include <iostream>

namespace reactor {

bool Reactor::shall_quit() {
  return (std::find(gui_events.begin(), gui_events.end(), events::QUIT) !=
          gui_events.end())
             ? false
             : true;
}

bool Reactor::update() {
  for (auto &event : gui_events)
    printf("%i \n", event);

  return this->shall_quit();
}

Reactor::Reactor(int argc, char **argv) {
  std::thread gui_thread(run, argc, argv, ref(this->gui_events));
  threads.push_back(std::move(gui_thread));

  for (auto &thread : threads)
    thread.detach();
}

} // end namespace reactor