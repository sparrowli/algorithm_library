#ifndef ALGORITHM_LIBRARY_SRC_LC_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H_
#define ALGORITHM_LIBRARY_SRC_LC_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H_

#include <string>

class LongestSubstringSolution {
 public:

  int LengthOfLongestSubstring(std::string& s);

  int GetLengthOfLongestSubstringBySlidingWindow(std::string& s);

  int GetLengthOfLongestSubstringByOptimizedSlidingWindow(std::string& s);

 protected:
  bool IsUnique(std::string& s, int start, int end);

};

#endif  // ALGORITHM_LIBRARY_SRC_LC_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H_
