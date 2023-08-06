/*
 152. Maximum Product Subarray

  Given an integer array nums, find a subarray that has the largest product, and
  return the product. The test cases are generated so that the answer will fit
  in a 32-bit integer.

  Example 1:
  Input: nums = [2,3,-2,4]
  Output: 6
  Explanation: [2,3] has the largest product 6.
*/

class Solution {
public:
  // Saves the largest (and smallest) product achievable either historically
  // within the subarray or by itself, which is done with dynamic programming.
  // Given n items in the vector, the Time Complexity is O(n).
  int maxProduct(vector<int> &nums) {
    int size = nums.size();
    // Initialise two vectors to store the largest and smallest products up to
    // each point
    vector<int> maxProduct(size + 1);
    vector<int> minProduct(size + 1);
    // Base Case: An integer by itself cannot multiply with anything
    maxProduct[0] = nums[0];
    minProduct[0] = nums[0];
    // Initialize max_answer to the first number in the array
    int max_answer = nums[0];
    // Recursive Case: Keep both maxProduct and minProduct (in case a negative
    // number becomes the next largest product).
    for (int i = 1; i < size; i++) {
      maxProduct[i] = max(
          {maxProduct[i - 1] * nums[i], minProduct[i - 1] * nums[i], nums[i]});
      minProduct[i] = min(
          {maxProduct[i - 1] * nums[i], minProduct[i - 1] * nums[i], nums[i]});
      max_answer = max(max_answer, maxProduct[i]);
    }
    return max_answer;
  }
};