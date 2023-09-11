class Solution(object):
    def maxProfit(self, prices):
        """
        You are given an array prices where prices[i] is the price of
        a given stock on the ith day.

        You want to maximize your profit by choosing a single day to
        buy one stock and choosing a different day in the future to sell
        that stock.

        Return the maximum profit you can achieve from this transaction.
        If you cannot achieve any profit, return 0.

        :type prices: List[int]
        :rtype: int
        """
        maxProfit = 0
        for i in range(len(prices)):
            for j in range((i + 1), len(prices)):
                if prices[j] - prices[i] > maxProfit:
                    maxProfit = prices[j] - prices[i]
        return maxProfit

    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # Implement the two pointers strategy
        maxVal, left= 0
        for i in range(1, len(prices)):
            if prices[i] < prices[left]:
                left = i
            if prices[i] - prices[left] > maxVal:
                maxVal = prices[i] - prices[left]
        return maxVal