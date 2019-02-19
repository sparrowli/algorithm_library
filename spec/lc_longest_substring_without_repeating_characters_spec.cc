#include "src/lc_longest_substring_without_repeating_characters.h"

#include "spec/lc_clock.h"

#include "gtest/gtest.h"

class LongestSubstringSpec : public QuickTest {
 protected:
  virtual void SetUp() {
    QuickTest::SetUp();
  }

  virtual void TearDown() {
    QuickTest::TearDown();
  }

  LongestSubstringSolution s;
};

TEST_F(LongestSubstringSpec, NormalSubstring) {
  std::string input_str = "abcabcbb";

  int len = s.LengthOfLongestSubstring(input_str);

  EXPECT_EQ(len , sizeof("abc") - 1);
}

TEST_F(LongestSubstringSpec, RepeatedCharacters) {
  std::string input_str = "bbbbb";

  int len = s.LengthOfLongestSubstring(input_str);

  EXPECT_EQ(len , sizeof("b") - 1);
}

TEST_F(LongestSubstringSpec, DifferenceWithSubsequent) {
  std::string input_str = "pwwkew";

  int len = s.LengthOfLongestSubstring(input_str);

  EXPECT_EQ(len , sizeof("wke") - 1);
}

TEST_F(LongestSubstringSpec, NormalSubstringBySlidingWindow) {
  std::string input_str = "abcabcbb";

  int len_sliding = s.GetLengthOfLongestSubstringBySlidingWindow(input_str);

  EXPECT_EQ(len_sliding , sizeof("abc") - 1);
}

TEST_F(LongestSubstringSpec, RepeatedCharactersBySlidingWindow) {
  std::string input_str = "bbbbb";

  int len_sliding = s.GetLengthOfLongestSubstringBySlidingWindow(input_str);

  EXPECT_EQ(len_sliding , sizeof("b") - 1);
}

TEST_F(LongestSubstringSpec, DifferenceWithSubsequentBySlidingWindow) {
  std::string input_str = "pwwkew";

  int len_sliding = s.GetLengthOfLongestSubstringBySlidingWindow(input_str);

  EXPECT_EQ(len_sliding , sizeof("wke") - 1);
}

TEST_F(LongestSubstringSpec, NormalSubstringByOptimizedSlidingWindow) {
  std::string input_str = "abcabcbb";

  int len_sliding = s.GetLengthOfLongestSubstringByOptimizedSlidingWindow(input_str);

  EXPECT_EQ(len_sliding , sizeof("abc") - 1);
}

TEST_F(LongestSubstringSpec, RepeatedCharactersByOptimizedSlidingWindow) {
  std::string input_str = "bbbbb";

  int len_sliding = s.GetLengthOfLongestSubstringByOptimizedSlidingWindow(input_str);

  EXPECT_EQ(len_sliding , sizeof("b") - 1);
}

TEST_F(LongestSubstringSpec, DifferenceWithSubsequentByOptimizedSlidingWindow) {
  std::string input_str = "pwwkew";

  int len_sliding = s.GetLengthOfLongestSubstringByOptimizedSlidingWindow(input_str);

  EXPECT_EQ(len_sliding , sizeof("wke") - 1);
}