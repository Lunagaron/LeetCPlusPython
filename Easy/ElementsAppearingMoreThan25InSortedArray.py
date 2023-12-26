class Solution(object):
    def findSpecialInteger(self, arr):
        """
        Given an integer array sorted in non-decreasing order, there is
        exactly one integer in the array that occurs more than 25% of
        the time, return that integer.

        Input: arr = [1,2,2,6,6,6,6,7,10]
        Output: 6

        :type arr: List[int]
        :rtype: int
        """
        length = len(arr) / 4
        word = arr[0]
        count = 0
        for i in arr:
            if i != word:
                word = i
                count = 1
                continue
            else:
                count += 1
            if count > int(length):
                return int(word)
