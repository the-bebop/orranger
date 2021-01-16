#include <hpp/moderator.hpp>
#include <mutex>

namespace moderator {

void Moderator::set_event(events::MainControls new_event) {

  if (event_lock.try_lock()) {
    events.push_back(new_event);
    event_lock.unlock();
  }
}

std::vector<events::MainControls> Moderator::get_events() {

  std::vector<events::MainControls> ret_vec;
  if (event_lock.try_lock()) {
    ret_vec = events;
    events.clear();
    event_lock.unlock();
  }

  return ret_vec;
}

} // namespace moderator