/*
  121.Best Time to Buy and Sell Stock

  You are given an array prices where prices[i] is the price of a given stock on
  the ith day. You want to maximize your profit by choosing a single day to buy
  one stock and choosing a different day in the future to sell that stock.
  Return the maximum profit you can achieve from this transaction. If you cannot
  achieve any profit, return 0.

  Example 1:

  Input: prices = [7,1,5,3,6,4]
  Output: 5
  Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit =
  6-1 = 5. Note that buying on day 2 and selling on day 1 is not allowed because
  you must buy before you sell.
 */

class Solution {
public:
  // Normal method keeping two variables to keep track of the lowest cost ever
  // found up until that point and the max profit that could be turned. Only
  // iterates through prices once. Time Complexity O(n).
  int maxProfit(vector<int> &prices) {
    // Initialise variables lowest price found and highest profit possible
    int lowest_price = std::numeric_limits<int>::max();
    int profit = 0;
    int size = prices.size();
    for (int i = 0; i < size; i++) {
      // Check if this is the lowest price possible
      if (prices[i] < lowest_price) {
        lowest_price = prices[i];
      }
      // Check if this could be the largest profit return
      if (prices[i] - lowest_price > profit) {
        profit = prices[i] - lowest_price;
      }
    }
    return profit;
  }
};