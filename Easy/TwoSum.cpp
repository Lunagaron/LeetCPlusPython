/*
  1. Two Sum
  Given an array of integers nums and an integer target, return indices of the
  two numbers such that they add up to target. You may assume that each input
  would have exactly one solution, and you may not use the same element twice.
  You can return the answer in any order.
 */

#include <vector>

class Solution {
public:
  // Traditional Solution for-loop with Time Complexity O(n^2)
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (i != j && nums[i] + nums[j] == target) {
          return {i, j};
        }
      }
    }
    return {};
  }

  // Hash-Map Solution with Time Complexity O(n)
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> pairs;
    for (int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];
      // If there is a match already in the map
      if (pairs.find(complement) != pairs.end()) {
        // Return the pair of numbers
        return {pairs[complement], i};
      }
      // Otherwise, insert key nums[i] with value i into the map
      pairs[nums[i]] = i;
    }
    return {};
  }
};
