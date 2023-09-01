class Solution(object):
    def containsDuplicate(self, nums):
        """
        Given an integer array nums, return true if any value appears at least
        twice in the array, and return false if every element is distinct. Time
        Complexity is O(n), time required to create the set numSet is O(n) and
        iterating through each element to remove from the set is also O(n) in
        worst case scenario.

        :type nums: List[int]
        :rtype: bool
        """
        numSet = set(nums)
        for num in nums:
            if num in numSet:
                numSet.remove(num)
            else:
                return True
        return False
