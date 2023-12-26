class Solution:
    def minOperations(self, s: str) -> int:
        # Odd pattern for 0101, Even pattern for 1010
        count_odd = 0
        count_even = 0
        for i in range(len(s)):
            # If it is an even-indexed number
            if i % 2 == 0:
                if int(s[i]) == 0:
                    count_even += 1
                    # print(f"Even counter incremeneted")
                if int(s[i]) == 1:
                    count_odd += 1
                    # print(f"Odd counter incremeneted")
            else:
                if int(s[i]) == 0:
                    count_odd += 1
                    # print(f"Odd counter incremeneted")
                if int(s[i]) == 1:
                    count_even += 1
                    # print(f"Even counter incremeneted")
        # print(f"Even counter {count_even} and Odd counter {count_odd}")
        return min(count_odd, count_even)
