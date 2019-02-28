#ifndef ALGORITHM_LIBRARY_SRC_LC_LONGEST_PALINDROMIC_H_
#define ALGORITHM_LIBRARY_SRC_LC_LONGEST_PALINDROMIC_H_

#include <string>

class LongestPalindromeSolution {
 public:
  std::string Longest_Palindrome(std::string s);

  std::string longest_common_substring_with_reverse_string(std::string s);

  std::string Longest_PalindromeByExpandAroundCenter(std::string s);
 private:
  int ExpandAroundCenter(std::string s, int left, int right);
};

#endif  // ALGORITHM_LIBRARY_SRC_LC_LONGEST_PALINDROMIC_H_