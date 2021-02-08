#ifndef backend_moderator_hpp_main
#define backend_moderator_hpp_main

#include <backend/processors/dummy/hpp/dummy.hpp>
#include <condition_variable>
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
  std::unique_lock<std::mutex> unique_event_lock;
  std::condition_variable lock_condition;
  std::chrono::seconds wait_on_unlock_period;

  // const std::chrono::time_point<std::chrono::seconds> get_wait_limit();

public:
  void set_event(events::MainControls new_event);
  void get_events(std::vector<events::MainControls> &current_events);
  Moderator();
};

} // namespace moderator
#endif // backend_moderator_hpp_main