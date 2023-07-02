/*
  189. Rotate Array

  Given an integer array nums, rotate the array to the right by k steps, where k
  is non-negative.

  Example 1:

  Input: nums = [1,2,3,4,5,6,7], k = 3
  Output:       [5,6,7,1,2,3,4]

  Explanation:
  rotate 1 steps to the right: [7,1,2,3,4,5,6]
  rotate 2 steps to the right: [6,7,1,2,3,4,5]
  rotate 3 steps to the right: [5,6,7,1,2,3,4]
 */

class Solution {
public:
  // Worst solution: Shift the numbers one by one as shown in the example. Time
  // Complexity O(k * n)
  void rotate(vector<int> &nums, int k) {
    // Get size of nums array
    int size = nums.size();
    // Begin rotation iteration
    int rotation = 0;
    while (rotation < k) {
      for (int i = size - 1; i > 0; i--) {
        std::swap(nums[i], nums[i - 1]);
      }
      rotation++;
    }
  }

  // Alternative solution: Make a duplicate vector and move each element k
  // places to the right. Time Complexity O(n)
  void rotate(vector<int> &nums, int k) {
    // Make a copy
    vector<int> copy = nums;
    int size = nums.size();
    // Write over places
    for (int i = 0; i < size; i++) {
      nums[(i + k) % size] = copy[i];
    }
  }

  // Alternative solution: One efficient approach is to reverse the entire
  // array, then reverse the first k elements, and finally reverse the remaining
  // n-k elements. Time Complexity : O(n)
  void rotate(vector<int> &nums, int k) {
    int size = nums.size();
    // If number of rotations is greater than size, remove looped rotations
    k = k % size;
    // Reverse the entire array - must use iterators NOT individual elements
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};