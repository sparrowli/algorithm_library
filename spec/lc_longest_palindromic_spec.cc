#include "src/lc_longest_palindromic.h"

#include "spec/lc_clock.h"
#include "gtest/gtest.h"

class FindLongestPalindromicStringSpec : public QuickTest {
 protected:
  virtual void SetUp() {
    QuickTest::SetUp();
  }
  virtual void TearDown() {
    QuickTest::TearDown();
  }

 LongestPalindromeSolution s;
};

// hint 1: How can we reuse the previously computed palindrome to 
// compute a larger palindrame?


// hint 2: If "aba" is a palindrome, is "xabax" also a palindrome?
// Similary is "xabay" a palindrome?

// hint 3: 

TEST_F(FindLongestPalindromicStringSpec, TheSimplestPalindrome) {
  std::string str = "cbbd";
  std::string palindrome = "bb";

  std::string actual_palindrome = s.Longest_Palindrome(str);

  std::string actual_p = s.Longest_PalindromeByExpandAroundCenter(str);
  EXPECT_EQ(palindrome, actual_p);

  EXPECT_EQ(palindrome, actual_palindrome);
}

TEST_F(FindLongestPalindromicStringSpec, ReturnPalindrome) {
  std::string str = "babad";
  std::string palindrome = "aba";

  std::string actual_palindrome = s.Longest_Palindrome(str);
  EXPECT_EQ(palindrome, actual_palindrome);

  std::string actual_p = s.Longest_PalindromeByExpandAroundCenter(str);
  EXPECT_EQ(palindrome, actual_p);
  
}

TEST_F(FindLongestPalindromicStringSpec, LongestCommonSubstring) {
  std::string str = "babad";
  std::string lc_string = "aba";
  std::string actual_lc_string = s.longest_common_substring_with_reverse_string(str);
  EXPECT_EQ(lc_string, actual_lc_string);

  std::string actual_p = s.Longest_PalindromeByExpandAroundCenter(str);
  EXPECT_EQ(lc_string, actual_p);
  
}

TEST_F(FindLongestPalindromicStringSpec, LongestCommonSubstringWithFlawed) {
  std::string str = "abacdfgdcaba";
  std::string lc_string = "aba";
  std::string actual_lc_string = s.longest_common_substring_with_reverse_string(str);
  // The flawed in longest common 
  EXPECT_EQ(lc_string, actual_lc_string);

  std::string actual_p = s.Longest_PalindromeByExpandAroundCenter(str);
  EXPECT_EQ(lc_string, actual_p);
}