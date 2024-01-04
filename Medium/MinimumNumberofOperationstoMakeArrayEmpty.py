class Solution:
    def minOperations(self, nums: List[int]) -> int:
        recurrence = {}
        min_operations = 0
        # Populate the dictionary
        for num in nums:
            if num not in recurrence:
                recurrence[num] = 1
            else:
                recurrence[num] += 1
        # Iterate through each number and analyse individually
        for key, val in recurrence.items():
            # If a combination cannot be made (only applies to 1)
            if val <= 1:
                return -1
            while val > 5:
                min_operations += 1
                val -= 3
                # print(f"{key} has {val} : operation count {min_operations} ")
            if val == 5 or val == 4:
                min_operations += 2
                # print(f"{key} has {val} : operation count {min_operations} ")
                continue
            elif val == 3 or val == 2:
                # print(f"{key} has {val} : operation count {min_operations} ")
                min_operations += 1
                continue
        return min_operations
