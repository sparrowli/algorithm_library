#ifndef ALGORITHM_LIBRARY_SRC_LEETCODE_ALGORITHM_H_
#define ALGORITHM_LIBRARY_SRC_LEETCODE_ALGORITHM_H_

#include <vector>

class Solution {
 public:
  std::vector<int> TwoSum(std::vector<int>& nums, int target);

  std::vector<int> TwoSumByHash(std::vector<int>& nums, int target);
  
  std::vector<int> TwoSumByOnePassHash(std::vector<int>& nums, int target);
};

#endif  // ALGORITHM_LIBRARY_SRC_LEETCODE_ALGORITHM_H_