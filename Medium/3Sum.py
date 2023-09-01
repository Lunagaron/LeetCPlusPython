class Solution(object):
    def threeSum(self, nums):
        """
        Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
        such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
        Notice that the solution set must not contain duplicate triplets. The idea of this
        question is to first order the array, and for each negative index that is not a
        duplicate of a previous number, perform the 2Sum search for the negative of the
        value with two pointers. Time Complexity of sorting is O(n logn), and the two
        pointers iterating through the set has time complexity of O(n^2). Therefore,
        Time Complexity O(n^2)

        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) < 3:
            return []
        nums.sort()  # Sort the numbers into non-decreasing order
        solution = []  # Initialise an empty array to store solutions

        for index, value in enumerate(nums):
            # If there was a duplicate of this number in the index before
            if index > 0 and value == nums[index - 1]:
                continue

            # If there are only positive numbers remaining
            if value > 0:
                return solution

            # Initialise two pointer to turn into 2Sum problem
            left = index + 1
            right = len(nums) - 1

            while left < right:
                if nums[left] + nums[right] < -value:
                    left += 1
                elif nums[left] + nums[right] > -value:
                    right -= 1
                else:
                    solution.append([value, nums[left], nums[right]])
                    left += 1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
        return solution
