/*
  300. Longest Increasing Subsequence

  Given an integer array nums, return the length of the longest strictly
  increasing subsequence.

  Example 1:
  Input: nums = [10,9,2,5,3,7,101,18]
  Output: 4
  Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
  length is 4.
*/

class Solution {
public:
  // Utilises dynamic programming to iteratively backtrack and check the longest
  // existing increasing subsequence it can attach to. Time Complexity O(n^2).
  int lengthOfLIS(vector<int> &nums) {
    int size = nums.size();
    vector<int> lis(size, 0);
    // Base Case: Max longest increasing subsequence of one element is one.
    int max_length = 1;
    lis[0] = 1;
    // Recurrence Case: i is to keep count of current index, j is to reverse and
    // check all previous indices.
    for (int i = 1; i < size; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (nums[i] > nums[j]) {
          lis[i] = max(lis[j] + 1, lis[i]);
        }
      }
      lis[i] = max(1, lis[i]);
      max_length = max(max_length, lis[i]);
    }
    return max_length;
  }
};