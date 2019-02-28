#include "src/lc_longest_palindromic.h"

#include <unordered_map>
#include <iostream>

std::string LongestPalindromeSolution::Longest_Palindrome(std::string s) {
  std::string palindrome = "bb";
  
  std::string longest_common_substring;

  int len = s.size();
  
  longest_common_substring = longest_common_substring_with_reverse_string(s);

  return longest_common_substring;
}

std::string LongestPalindromeSolution::longest_common_substring_with_reverse_string(std::string s) {
  std::string longest_common_substring = "";
  int len = s.size();

  std::cout<<"len = "<<len<<std::endl;
  int i = 0;
  int j = 0;
  int max_len = 0;
  int sub_len = 0;

  std::string reverse_s(s.rbegin(), s.rend());
 
  std::unordered_map<std::string, int> sub_string_to_len;

  for (; i < len; ++i) {
    for (j = i; j < len; ++j) {
      sub_string_to_len.emplace(s.substr(i, j - i + 1), j - i +1);

      sub_len = sub_string_to_len[reverse_s.substr(i, j - i + 1)];
      if (sub_len > max_len) {
        max_len = sub_len;
        longest_common_substring = reverse_s.substr(i, j - i + 1);
      }
    }
  }

  std::cout<<"longest substring len = "<<max_len<<std::endl;

  return longest_common_substring;
}

// time complexity: O(n ^ 2)
// space complexity: O(1)

std::string LongestPalindromeSolution::Longest_PalindromeByExpandAroundCenter(std::string s) {
  int len = s.size();
  if (len < 1) return "";

  int start = 0;
  int end = 0;

  int len1 = 0;
  int len2 = 0;

  int max = 0;
  for (int i = 0; i < len; ++i) {
    len1 = ExpandAroundCenter(s, i, i);
    len2 = ExpandAroundCenter(s, i, i + 1);

    max = std::max(len1, len2);
    if (max > end - start) {
      start = i - (max - 1) / 2;
      end = i + max / 2;
    }
  }
  
  return s.substr(start, end);
}

int LongestPalindromeSolution::ExpandAroundCenter(std::string s, int left, int right) {
  int len = s.size();
  int L = left;
  int R = right;

  while (L >= 0 && R < len && s[L] == s[R]) {
    L--;
    R++;
  }

  return R - L - 1;
}