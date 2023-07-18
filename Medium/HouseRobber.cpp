/*
  198. House Robber

  You are a professional robber planning to rob houses along a street. Each
  house has a certain amount of money stashed, the only constraint stopping you
  from robbing each of them is that adjacent houses have security systems
  connected, and it will automatically contact the police if two adjacent houses
  were broken into on the same night. Given an integer array nums representing
  the amount of money of each house, return the maximum amount of money you can
  rob tonight without alerting the police.

  Example 1:
  Input: nums = [1,2,3,1]
  Output: 4
  Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3). Total
  amount you can rob = 1 + 3 = 4.

  Constraints:
  1 <= nums.length <= 100
  0 <= nums[i] <= 400
*/

class Solution {
public:
  // This problem utilises dynamic programming to store the entries of the max
  // loot that is heist-able from each successive house, and calculates the max
  // of the next house based on the previous max looting. Time Complexity O(n),
  // as it references back three previous houses which is a constant operation
  // O(3).
  int rob(vector<int> &nums) {
    // Number of houses to steal from
    int n = nums.size();
    // Corner cases of only one or two houses to heist
    if (n == 1) {
      return nums[0];
    }
    if (n == 2) {
      return max(nums[0], nums[1]);
    }
    // Initialise array to find best heist at any house in range of n
    vector<int> heistCash(n, 0);
    // Initialise first house loot
    heistCash[0] = nums[0];
    heistCash[1] = nums[1];
    heistCash[2] = max(nums[0] + nums[2], nums[1]);
    for (int i = 3; i < n; i++) {
      // Identify max loot possible
      heistCash[i] = max(max(heistCash[i - 1], heistCash[i - 2] + nums[i]),
                         heistCash[i - 3] + nums[i]);
    }
    return heistCash[n - 1];
  }
};