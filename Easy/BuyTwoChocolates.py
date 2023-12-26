class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        # Initialize the two lowest prices to the first two elements in the list
        lowest = min(prices[0], prices[1])
        second_lowest = max(prices[0], prices[1])

        # Iterate through the list to get the two lowest prices possible
        for price in prices[2:]:
            if price == lowest:
                second_lowest = price
            elif price < lowest:
                second_lowest = lowest
                lowest = price
            elif price < second_lowest:
                second_lowest = price
        total_cost = lowest + second_lowest
        if money < total_cost:
            return money
        else:
            return money - total_cost
