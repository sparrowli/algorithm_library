#include "lc_longest_substring_without_repeating_characters.h"

#include <unordered_map>
#include <unordered_set>
#include <iostream>


bool LongestSubstringSolution::IsUnique(std::string& s, int start, int end) {
  std::unordered_set<char> character_set;

  for (int i = start; i < end; ++i) {
    char c = s.at(i);

    if (character_set.find(c) != character_set.end()) {
      return false;
    }

    character_set.emplace(c);
  }
  
  return true;
}

int LongestSubstringSolution::LengthOfLongestSubstring(std::string& s) {
  int max_len = 0;

  int len = s.size();

  for (int i = 0; i < len - 1; ++i) {
    for (int j = i + 1; j < len; ++j) {
      
      if (IsUnique(s, i, j)) {
        max_len = std::max(max_len, j - i);
      }
    }
  }

  return max_len;
}

int LongestSubstringSolution::GetLengthOfLongestSubstringBySlidingWindow(std::string& s) {
  int max_len = 0;

  int len = s.size();

  int i = 0;
  int j = 0;

  std::unordered_set<char> character_set;
  while (i < len && j < len) {
    if (character_set.find(s.at(j)) == character_set.end()) {
      character_set.emplace(s.at(j++));
      max_len = std::max(max_len, j - i);
    } else {
      character_set.erase(s.at(i++));
    }
  }

  return max_len;
}

int LongestSubstringSolution::GetLengthOfLongestSubstringByOptimizedSlidingWindow(std::string& s) {
  int max_len = 0;
  int len = s.size();

  int i = 0;
  int j = 0;

  std::unordered_map<char, int> char_map_to_index;
  for (; j < len; ++j) {
    if (char_map_to_index.find(s.at(j)) != char_map_to_index.end()) {
      i = std::max(char_map_to_index.find(s.at(j))->second, j);
    }

    max_len = std::max(max_len, j - i + 1);
    char_map_to_index.emplace(s.at(j), j);
  }

  return max_len;
}