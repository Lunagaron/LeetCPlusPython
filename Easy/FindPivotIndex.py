class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        leftsum = 0
        rightsum = sum(nums)

        for i, j in enumerate(nums):
            if i == 0:
                leftsum = 0
            else:
                leftsum += nums[i - 1]
            rightsum -= j
            if leftsum == rightsum:
                return i
        return -1
