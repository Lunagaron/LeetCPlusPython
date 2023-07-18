/*
  213. House Robber II

  You are a professional robber planning to rob houses along a street. Each
  house has a certain amount of money stashed. All houses at this place are
  arranged in a circle. That means the first house is the neighbor of the last
  one. Meanwhile, adjacent houses have a security system connected, and it will
  automatically contact the police if two adjacent houses were broken into on
  the same night. Given an integer array nums representing the amount of money
  of each house, return the maximum amount of money you can rob tonight without
  alerting the police.

  Example 1:
  Input: nums = [2,3,2]
  Output: 3
  Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money =
  2), because they are adjacent houses.
 */

class Solution {
public:
  // This problem utilises dynamic programming to store the entries of the max
  // loot that is heist-able from each successive house, and calculates the max
  // of the next house based on the previous max looting. This is a direct copy
  // from House Robber, except that there now is two trackers for the maximum
  // element, one excluding the first house and the other excluding the last
  // house (to prevent two consecutive houses). Time Complexity O(n), as it
  // references back three previous houses which is a constant operation O(3)
  // which is repeated twice for each tracker of maximum value.
  int rob(vector<int> &nums) {
    // Number of houses to steal from
    int n = nums.size();
    // Corner cases of only one, two, or three houses to heist. Simplified to
    // find max element
    if (n <= 3) {
      return *max_element(nums.begin(), nums.end());
    }
    // Initialise array to find best heist at any house in range of n excluding
    // the last house and including first house
    vector<int> heistFirst(n, 0);
    // Initialise first house loot
    heistFirst[0] = nums[0];
    heistFirst[1] = nums[1];
    heistFirst[2] = max(nums[0] + nums[2], nums[1]);
    for (int i = 3; i < n; i++) {
      // Identify max loot possible
      heistFirst[i] = max(max(heistFirst[i - 1], heistFirst[i - 2] + nums[i]),
                          heistFirst[i - 3] + nums[i]);
    }
    // Initialise array to find best heist at any house in range of n excluding
    // the first house and including the last house
    vector<int> heistLast(n, 0);
    // Initialise first house loot
    heistLast[1] = nums[1];
    heistLast[2] = nums[2];
    heistLast[3] = max(nums[1] + nums[3], nums[2]);
    for (int i = 4; i < n; i++) {
      // Identify max loot possible
      heistLast[i] = max(max(heistLast[i - 1], heistLast[i - 2] + nums[i]),
                         heistLast[i - 3] + nums[i]);
    }

    return max(heistFirst[n - 2], heistLast[n - 1]);
  }
};