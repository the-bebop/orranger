#include <condition_variable>
#include <hpp/moderator.hpp>
#include <mutex>

namespace moderator {

Moderator::Moderator() {
  wait_on_unlock_period = std::chrono::seconds(2); // s
  unique_event_lock = std::unique_lock<std::mutex>(event_lock);
  unique_event_lock.unlock();
}

void Moderator::set_event(events::MainControls new_event) {

  const std::lock_guard<std::mutex> lock(event_lock);
  events.push_back(new_event);
}

void Moderator::get_events(std::vector<events::MainControls> &current_events) {

  const std::lock_guard<std::mutex> lock(event_lock);
  std::vector<events::MainControls> ret_vec;
  std::copy(events.begin(), events.end(), std::back_inserter(current_events));
  events.clear();
}
} // namespace moderator