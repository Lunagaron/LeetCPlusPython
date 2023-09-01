/*
 238. Product of Array Except Itself

 Given an integer array nums, return an array answer such that answer[i] is
equal to the product of all the elements of nums except nums[i]. The product of
any prefix or suffix of nums is guaranteed to fit in a 32-bit integer. You
must write an algorithm that runs in O(n) time and without using the division
operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/

class Solution {
public:
  // Keeps track of two vectors, one that cumulatively multiplies in the
  // forwards direction of prefixes and another in the backwards direction of
  // suffixes. By combining these two arrays, any product without a key index
  // can be found. Time Complexity O(n).
  vector<int> productExceptSelf(vector<int> &nums) {
    // Create two vectors, each to store the cumulative prefix and suffix
    int n = nums.size();
    std::vector<int> prefix(n, 0);
    std::vector<int> suffix(n, 0);

    // Iterate through and build up these arrays
    prefix[0] = nums[0];
    suffix[0] = nums[n - 1];
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] * nums[i];
      suffix[i] = suffix[i - 1] * nums[n - 1 - i];
    }

    // Build up answer
    std::vector<int> answer(n, 0);
    answer[0] = suffix[n - 2];
    answer[n - 1] = prefix[n - 2];
    for (int i = 1; i < n - 1; i++) {
      answer[i] = prefix[i - 1] * suffix[n - 2 - i];
    }

    return answer;
  }
};