#ifndef backend_moderator_hpp_main
#define backend_moderator_hpp_main

#include <backend/processors/dummy/hpp/dummy.hpp>
#include <frontends/common/gui_events.hpp>
#include <mutex>

#include <thread>
#include <vector>

namespace moderator {

/**
 * @brief Moderator is the event / signal handler
 *
 */
class Moderator {
private:
  std::vector<events::MainControls> events;
  std::mutex event_lock;

public:
  void set_event(events::MainControls new_event);
  std::vector<events::MainControls> get_events();
};

} // namespace moderator
#endif // backend_moderator_hpp_main