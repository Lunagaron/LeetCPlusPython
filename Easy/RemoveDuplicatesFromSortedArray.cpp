/*
  26. Remove Duplicates from Sorted Array

  Given an integer array nums sorted in non-decreasing order, remove the
  duplicates in-place such that each unique element appears only once. The
  relative order of the elements should be kept the same. Then return the number
  of unique elements in nums. Consider the number of unique elements of nums to
  be k, to get accepted, you need to do the following things:

  Change the array nums such that the first k elements of nums contain the
  unique elements in the order they were present in nums initially. The
  remaining elements of nums are not important as well as the size of nums.
  Return k.

  Example 1:

  Input: nums = [1,1,2]
  Output: 2, nums = [1,2,_]
  Explanation: Your function should return k = 2, with the first two elements of
  nums being 1 and 2 respectively. It does not matter what you leave beyond the
  returned k (hence they are underscores).
 */

class Solution {
public:
  // Standard implementation: Iterate through the vector once and add any new
  // non-repeating elements to a new vector. Time Complexity O(n)
  int removeDuplicates(vector<int> &nums) {
    // Makes a new vector of size nums.size()
    std::vector<int> copy_vector(nums.size());
    // Counter for number of new elements
    int num_elements = 1;
    copy_vector[0] = nums[0];
    // Iterates from the second element to the last in nums vector
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[i - 1]) {
        copy_vector[num_elements] = nums[i];
        num_elements++;
      }
    }
    nums = copy_vector;
    return num_elements;
  }

  // Faster and smarter solution involving keeping two pointers on the array,
  // one for iterating through and one to keep track of next position to insert
  // a new number. Uses less memory than the first implementation.
  // Time Complexity O(n).
  int removeDuplicates(vector<int> &nums) {
    // It is provided that the length of nums > 0
    int index = 1;
    int size = nums.size();
    for (int i = 1; i < size; i++) {
      if (nums[i] != nums[i - 1]) {
        nums[index] = nums[i];
        index++;
      }
    }
    return index;
  }
};