class Solution(object):
    def longestConsecutive(self, nums):
        """
        This function takes in a list of integers and returns the length of the
        longest consecutive sequence of integers in the list. It works by identifying
        the first number in a sequence and then iterating through the set until the
        sequence ends. It then compares the length of the sequence to the longest
        sequence found so far and updates the longest sequence if necessary. The time
        complexity of this algorithm is O(n) because it iterates through the set once
        and the space complexity is O(n) because it creates a set of the input list.

        :type nums: List[int]
        :rtype: int
        """
        numSet = set(nums)  # Turn the nums into a set
        longest = 0  # Keep a tracker of the longest consequetive sequence

        for num in numSet:  # Iterate through the set
            if (num - 1) not in numSet:  # If the number before isnt in the set
                iterator = 0
                while (num + iterator) in numSet:  # Identify longest sequence
                    iterator += 1
                longest = max(longest, iterator)
        return longest
