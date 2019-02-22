#include "src/lc_median_of_two_sorted_arrays.h"

#include "spec/lc_clock.h"
#include "gtest/gtest.h"

class MedianSolutionSpec : public QuickTest {
 protected:
  virtual void SetUp() {
    QuickTest::SetUp();
  }

  virtual void TearDown() {
    QuickTest::TearDown();
  }

  MedianSolution s;
};

// What's the definition of median?
// 2nd point: merge two sorted arrays to one sorted array? merge sort

TEST_F(MedianSolutionSpec, GetMedianWithOddElements) {
  std::vector<int> a1 = {1, 3};
  std::vector<int> a2 = {2};

  double expect_val = 2.0;
  double actual_val = s.FindMedianSortedArrays(a1, a2);

  EXPECT_EQ(expect_val, actual_val);
}

TEST_F(MedianSolutionSpec, GetMedianWithEvenElements) {
  std::vector<int> a1 = {1, 5};
  std::vector<int> a2 = {3, 6};

  double expect_val = 4.0;
  double actual_val = s.FindMedianSortedArrays(a1, a2);

  EXPECT_EQ(expect_val, actual_val);
}