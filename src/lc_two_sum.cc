#include "src/lc_two_sum.h"

#include <iostream>
#include <unordered_map>

std::vector<int> Solution::TwoSum(std::vector<int>& nums, int target) {
  std::vector<int> indices;
  int first_index = -1;
  int second_index = -1;

  size_t len = nums.size();

  std::vector<int>::iterator i;

  for (i = nums.begin(); i != nums.end(); ++i) {
        
  }

  for (int k = 0; k < len; ++k) {
    first_index = k;
    std::vector<int>::iterator sec_index = std::find(nums.begin(), nums.end(), target - nums[k]);

    if (sec_index != nums.end()) {
      second_index = std::distance(nums.begin(), sec_index);
      indices.emplace_back(first_index);
      indices.emplace_back(second_index);

      return indices;
    }

    /*
    for (int n = k + 1; n < len; ++n) {

      

      if (nums[n] == target - nums[k]) {
        second_index = n;

        indices.emplace_back(first_index);
        indices.emplace_back(second_index);
        return indices;
      }

    }
    */

  }

  std::cout<<"There are no two numbers sumed equals to target"<<std::endl;

  return indices;
}

std::vector<int> Solution::TwoSumByHash(std::vector<int>& nums, int target) {
  std::vector<int> indices;

  std::unordered_map<int, size_t> hash_from_vector;
  size_t size_of_vector = nums.size();
  std::vector<int>::iterator it;

  // two-pass hash table
  // The first pass/iteration
  for (size_t i = 0; i < size_of_vector; ++i) {
    hash_from_vector[nums[i]] = i;
  }

  std::unordered_map<int, size_t>::iterator map_it;

  for (it = nums.begin(); it != nums.end(); ++it) {

    map_it = hash_from_vector.find(target - *it);

    // Check if each element's complement exist in the table
    // Beware that the complement mustnot be nums[i] itself
    if (map_it != hash_from_vector.end()
               && map_it->second != std::distance(nums.begin(), it)) {
      indices.emplace_back(std::distance(nums.begin(), it));
      indices.emplace_back(map_it->second);
      return indices;
    }

    std::cout<<std::endl;

  }
  
  return indices;
}

std::vector<int> Solution::TwoSumByOnePassHash(std::vector<int>& nums, int target) {
  std::vector<int> indices;

  std::unordered_map<int, size_t> hash_from_vector;
  std::unordered_map<int, size_t>::iterator map_it;

  size_t size_of_vector = nums.size();

  for (size_t i = 0; i < size_of_vector; ++i) {
    hash_from_vector[nums[i]] = i;
    map_it = hash_from_vector.find(target - nums[i]);

    if (map_it != hash_from_vector.end()) {
      return std::vector<int> {static_cast<int>(map_it->second), static_cast<int>(i)};
    }
  }

  return indices;
}