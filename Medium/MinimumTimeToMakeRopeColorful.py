class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        # Declare helper variables
        total_time = 0
        # Maximum time to remove a balloon of the current colour (NOT OK!)
        max_time = 0
        # Current sum of non-duplicated balloons (OK!)
        current_sum = 0
        current_color = None

        # Iterate through the colours
        for i in range(len(colors)):
            # If the current colour is not a duplicate
            if colors[i] != current_color:
                total_time += current_sum - max_time
                current_color = colors[i]
                current_sum = 0
                max_time = 0

            current_sum += neededTime[i]
            max_time = max(max_time, neededTime[i])

        # Add the last sequence
        total_time += current_sum - max_time

        return total_time
