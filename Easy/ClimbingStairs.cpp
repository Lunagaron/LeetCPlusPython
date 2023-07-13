/*
  70. Climbing Stairs

  You are climbing a staircase. It takes n steps to reach the top. Each time you
  can either climb 1 or 2 steps. In how many distinct ways can you climb to the
  top?

  Example 1:
  Input: n = 2
  Output: 2
  Explanation: There are two ways to climb to the top.
                1. 1 step + 1 step
                2. 2 steps
 */
class Solution {
public:
  // The climbStairs algorithm uses dynamic programming to compute the number of
  // distinct ways to climb a staircase with n steps. Time Complexity of O(n)
  int climbStairs(int n) {
    // Special return condition if n is less than or equal 2 steps
    if (n <= 2) {
      return n;
    }
    // Creates a vector to store the number of ways to climb the stairs.
    std::vector<int> stairCases(n, 0);
    stairCases[0] = 1;
    stairCases[1] = 2;
    // Compute the number of ways to climb the stairs using dynamic programming.
    for (int i = 2; i < n; i++) {
      stairCases[i] = stairCases[i - 1] + stairCases[i - 2];
    }
    return stairCases[n - 1];
  }
};