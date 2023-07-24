/*
  167. Two Sum II - Input Array Is Sorted

  Given a 1-indexed array of integers numbers that is already sorted in
  non-decreasing order, find two numbers such that they add up to a specific
  target number. Let these two numbers be numbers[index1] and numbers[index2]
  where 1 <= index1 < index2 < numbers.length. Return the indices of the two
  numbers, index1 and index2, added by one as an integer array [index1, index2]
  of length 2. The tests are generated such that there is exactly one solution.
  You may not use the same element twice. Your solution must use only constant
  extra space.

  Example 1:
  Input: numbers = [2,7,11,15], target = 9
  Output: [1,2]
  Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We
  return [1, 2].
*/

class Solution {
public:
  // This implementation utilises two pointers at each end of the sorted array.
  // If the sum is equal, return the indices, otherwise if the sum is less than
  // the target, move the smaller left pointer higher up a number, otherwise the
  // move the larger right pointer lower if the sum is too high. Overall time
  // complexity is linear as each item in the array is only iterated through
  // once. Time Complexity O(n).
  vector<int> twoSum(vector<int> &numbers, int target) {
    // Maintain two pointers at each end of the array.
    int start = 0;
    int end = numbers.size() - 1;
    // While the pointers do not cross over one another
    while (start < end) {
      int sum = numbers[start] + numbers[end];
      if (sum == target) {
        return {start + 1, end + 1};
      } else if (sum < target) {
        // Move the smaller number higher
        start++;
      } else {
        // Move the larger number lower
        end--;
      }
    }
    // Will not happen since guaranteed to return a result, placeholder.
    return {0, 0};
  }
};