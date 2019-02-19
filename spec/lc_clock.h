#include "src/current_clock.h"

#include "gtest/gtest.h"


class QuickTest : public testing::Test {
 protected:
  // Remember that SetUp() is run immediately before a test starts.
  // This is a good place to record the start time.
  virtual void SetUp() { 
    start_time_ms_ = clock_.Milliseconds();
  }

  // TearDown() is invoked immediately after a test finishes.  Here we
  // check if the test was too slow.
  virtual void TearDown() {
    // Gets the time when the test finishes
    elapsed_ms_ = clock_.Milliseconds() - start_time_ms_;

    // Asserts that the test took no more than ~5 seconds.  Did you
    // know that you can use assertions in SetUp() and TearDown() as
    // well?
    EXPECT_TRUE(elapsed_ms_ <= 5000) << "The test took too long.";

    std::cout<<"\nRuntime: "<< elapsed_ms_ << "ms" << std::endl;
  }

  // The UTC time (in microseconds) when the test starts
  uint64_t start_time_ms_;
  uint64_t elapsed_ms_;

  //std::chrono::high_resolution_clock clock_;
  CurrentClock clock_;
};