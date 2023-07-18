/*
  746. Min Cost Climbing Stairs

  You are given an integer array cost where cost[i] is the cost of ith step on a
  staircase. Once you pay the cost, you can either climb one or two steps. You
  can either start from the step with index 0, or the step with index 1. Return
  the minimum cost to reach the top of the floor.

  Example 1:
  Input: cost = [10,15,20]
  Output: 15
  Explanation: You will start at index 1.
  - Pay 15 and climb two steps to reach the top.
  The total cost is 15.

  Constraints:
  2 <= cost.length <= 1000
  0 <= cost[i] <= 999
  */

class Solution {
public:
  // Dynamic Programming Solution stores the best path to each step along the
  // stairs and uses it to decide the next steps. Time Complexity O(n), as the
  // algorithm iterates through each item once while only peeking back to the
  // past 2 entries which takes constant time.
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    // Stores cost of climbing up to every single step
    vector<int> stairCosts(n, 0);
    // Initialise first base-cases of climbing up to first step (free to start)
    stairCosts[0] = 0;
    stairCosts[1] = 0;
    // Begin dynamic programming finding cheapest cost for next set of stairs
    for (int i = 2; i < n; i++) {
      // Select best-case scenario
      stairCosts[i] =
          min(stairCosts[i - 2] + cost[i - 2], stairCosts[i - 1] + cost[i - 1]);
    }
    return min(stairCosts[n - 1] + cost[n - 1],
               stairCosts[n - 2] + cost[n - 2]);
  }
};