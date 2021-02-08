#ifndef backend_reactor_hpp_main
#define backend_reactor_hpp_main

#include <backend/processors/audio_gen/hpp/audio_gen.hpp>
#include <backend/processors/dummy/hpp/dummy.hpp>
#include <frontends/common/gui_events.hpp>
#include <hpp/moderator.hpp>

#include <thread>
#include <vector>

namespace reactor {

/**
 * @brief Reactor is the backbone of the program, where all components share a
 * common context
 *
 */
class Reactor {
private:
  processors::DummyProc proc;
  processors::AudioGenerator audio_gen;

  std::vector<std::thread> threads;
  moderator::Moderator moderator;

public:
  Reactor(int argc, char **argv);

  /**
   * @brief main loop that runs all component in a circular manner
   *
   * @return indication if the whole program can be exited
   */
  bool update();
};

} // namespace reactor
#endif // backend_reactor_hpp_main