class Solution:
    def maxScore(self, s: str) -> int:
        # Get the total number of zeros and ones in the list
        zeros = 0
        ones = 0
        for i in range(len(s)):
            # print(f"Current character {i}")
            if int(s[i]) == 0:
                zeros += 1
                # print(f"{s[i]} has been assigned 0")
            else:
                ones += 1
                # print(f"{s[i]} has been assigned 1")
        found_zeros = 0
        seen_ones = 0
        max_score = 0
        # Calculate the max score possible
        for i in range(len(s) - 1):
            if int(s[i]) == 0:
                found_zeros += 1
                if (found_zeros + ones - seen_ones) > max_score:
                    max_score = found_zeros + ones - seen_ones
                    # print(f"New score found: {max_score}")
            else:
                seen_ones += 1
                if (found_zeros + ones - seen_ones) > max_score:
                    max_score = found_zeros + ones - seen_ones
                    # print(f"New score found: {max_score}")
        return max_score
