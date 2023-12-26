class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        """
        Given the array of integers nums, you will choose
        two different indices i and j of that array. Return
        the maximum value of (nums[i]-1)*(nums[j]-1).
        """
        number_smaller = 0
        number_larger = 0
        n = len(nums)

        for i, j in enumerate(nums):
            if j > number_smaller:
                number_smaller = j
                temp1 = number_larger
                temp2 = number_smaller
                number_larger = max(temp1, temp2)
                number_smaller = min(temp1, temp2)
        return (number_larger - 1) * (number_smaller - 1)
