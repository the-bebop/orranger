#include <algorithm>
#include <frontends/basic/run.hpp>
#include <hpp/reactor.hpp>
#include <iostream>

namespace reactor {

bool Reactor::shall_quit() {
  auto gui_events = moderator.get_events();
  return (std::find(gui_events.begin(), gui_events.end(), events::QUIT) !=
          gui_events.end())
             ? false
             : true;
}

bool Reactor::update() {
  for (auto &event : moderator.get_events())
    printf("%i \n", event);

  return this->shall_quit();
}

Reactor::Reactor(int argc, char **argv) {
  std::thread gui_thread(run, argc, argv, std::ref(moderator));
  threads.push_back(std::move(gui_thread));

  for (auto &thread : threads)
    thread.detach();
}

} // end namespace reactor