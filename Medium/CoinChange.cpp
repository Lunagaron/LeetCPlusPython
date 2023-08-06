/*
  322. Coin Change

  You are given an integer array coins representing coins of different
  denominations and an integer amount representing a total amount of money.
  Return the fewest number of coins that you need to make up that amount. If
  that amount of money cannot be made up by any combination of the coins, return
  -1.

  Example 1:
  Input: coins = [1,2,5], amount = 11
  Output: 3
  Explanation: 11 = 5 + 5 + 1
  You may assume that you have an infinite number of each kind of coin.
 */

class Solution {
public:
  // Bottom-Up Dynamic Programming Solution which uses smaller sums of amounts
  // to reach the final answer. With coins n and an amount m, the Time
  // Complexity is O(m n).
  int coinChange(vector<int> &coins, int amount) {
    // Initialise a vector that stores the best way to get to each value
    vector<int> minCoins(amount + 1);
    // Base Case, no coins can be made of no coins
    minCoins[0] = 0;
    // Recursive Case building up from previous subproblems
    for (int i = 1; i <= amount; i++) {
      // Iterate through all coins
      for (int j = 0; j < coins.size(); j++) {
        // See if there is an optimal way to reach new sum with coin + sum -
        // coin
        if (i - coins[j] >= 0 && minCoins[i - coins[j]] != -1) {
          if (minCoins[i] == 0) {
            minCoins[i] = minCoins[i - coins[j]] + 1;
          } else {
            minCoins[i] = min(minCoins[i - coins[j]] + 1, minCoins[i]);
          }
        }
      }
      if (minCoins[i] == 0) {
        minCoins[i] = -1;
      }
    }
    return minCoins[amount];
  }
};