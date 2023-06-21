class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        answer = {}
        for index, value in enumerate(nums):
            find = target - value
            if find in answer:
                return [answer[find], index]
            answer[value] = index
