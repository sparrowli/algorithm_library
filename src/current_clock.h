#ifndef ALGORITHM_LIBRARY_SRC_CURRENT_CLOCK_H_
#define ALGORITHM_LIBRARY_SRC_CURRENT_CLOCK_H_

#include <chrono>

class CurrentClock {
 public:
  uint64_t Milliseconds() {
    return std::chrono::duration_cast<std::chrono::milliseconds>
              (clock_.now().time_since_epoch()).count();
  }
  uint64_t Microseconds() {
    return std::chrono::duration_cast<std::chrono::microseconds>
              (clock_.now().time_since_epoch()).count();
  }
  uint64_t Nanoseconds() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>
              (clock_.now().time_since_epoch()).count();
  }

 private:
  std::chrono::high_resolution_clock clock_;
};

#endif  // ALGORITHM_LIBRARY_SRC_CURRENT_CLOCK_H_