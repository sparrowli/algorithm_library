#include "src/lc_two_sum.h"

#include "spec/lc_clock.h"

#include "gtest/gtest.h"

namespace {

class LeetCodeSpec : public QuickTest {
 protected:

  virtual void SetUp() {
    QuickTest::SetUp();
  }

  virtual void TearDown() {
    QuickTest::TearDown();
  }

  Solution s;
};

TEST_F(LeetCodeSpec, TwoSum) {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  std::vector<int> expected_indices = {0, 1,};

  std::vector<int> indices = s.TwoSum(nums, target);
  EXPECT_EQ(2, indices.size());

  EXPECT_EQ(expected_indices, indices);
}

TEST_F(LeetCodeSpec, TwoSumAtEnd) {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 26;

  std::vector<int> expected_indices = {2, 3,};

  std::vector<int> indices = s.TwoSum(nums, target);
  EXPECT_EQ(2, indices.size());

  EXPECT_EQ(expected_indices, indices);
}

TEST_F(LeetCodeSpec, TwoSumAtEndByTwoPassHash) {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 26;

  std::vector<int> expected_indices = {2, 3,};

  std::vector<int> indices = s.TwoSumByHash(nums, target);
  EXPECT_EQ(2, indices.size());

  EXPECT_EQ(expected_indices, indices);
}

TEST_F(LeetCodeSpec, TwoSumAtEndByOnePassHash) {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 26;

  std::vector<int> expected_indices = {2, 3,};

  std::vector<int> indices = s.TwoSumByOnePassHash(nums, target);
  EXPECT_EQ(2, indices.size());

  EXPECT_EQ(expected_indices, indices);
}


TEST_F(LeetCodeSpec, TwoSumByOnePassHash) {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  std::vector<int> expected_indices = {0, 1,};

  std::vector<int> indices = s.TwoSumByOnePassHash(nums, target);
  EXPECT_EQ(2, indices.size());

  EXPECT_EQ(expected_indices, indices);
}

}  // namespace