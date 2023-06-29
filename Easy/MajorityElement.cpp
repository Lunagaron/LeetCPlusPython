/*
  169. Majority Element

  Given an array nums of size n, return the majority element. The majority
  element is the element that appears more than ⌊n / 2⌋ times. You may assume
  that the majority element always exists in the array.

  Example 1:
  Input: nums = [2,2,1,1,1,2,2]
  Output: 2
 */
#include <map>

class Solution {
public:
  // Standard Solution using a map to save the count of each number. If a number
  // exceeds the n/2 criteria, immediately return the number.
  // Time Complexity O(n log n)
  int majorityElement(vector<int> &nums) {
    // Corner case
    if (nums.size() == 1) {
      return nums[0];
    }
    // Create a map to update each count of each number in the vector nums
    std::map<int, int> my_map;
    // Initialise to immediately detect if a count is over n/2
    int majority_element = nums.size() / 2;
    for (int i = 0; i < nums.size(); i++) {
      auto it = my_map.find(nums[i]);
      // If a number is already inserted in my_map, increase count by 1
      if (it != my_map.end()) {
        my_map[nums[i]]++;
        // If a majority is reached, return. This can be done as it is
        // guaranteed to exist in question statement.
        if (my_map[nums[i]] > majority_element) {
          return nums[i];
        }
        // Otherwise, initialise number with a count of 1
      } else {
        my_map[nums[i]] = 1;
      }
    }
    // Dummy return
    return 0;
  }

  // Unique solution using Boyer-Moore's Majority Vote Algorithm. In this
  // updated code, we iterate through the nums vector and maintain a count
  // variable to keep track of the majority element. We start by assuming the
  // first element is the majority element and initialize the count as 1. Then,
  // for each subsequent element, if it matches the current majority element, we
  // increment the count. If it doesn't match, we decrement the count. When the
  // count reaches zero, we update the majority element to the current element
  // and reset the count to 1. Time Complexity O(n).
  int majorityElement(vector<int> &nums) {
    int majority_element = nums[0];
    int count = 1;

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == majority_element) {
        count++;
      } else {
        count--;
        if (count == 0) {
          majority_element = nums[i];
          count = 1;
        }
      }
    }

    return majority_element;
  }
};
