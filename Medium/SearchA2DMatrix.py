class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        You are given an m x n integer matrix matrix with the following two properties:
        Each row is sorted in non-decreasing order.
        The first integer of each row is greater than the last integer of the previous row.
        Given an integer target, return true if target is in matrix or false otherwise.
        You must write a solution in O(log(m * n)) time complexity.

        This code conducts a binary search over the 2D Matrix by indexing it in a way that is
        identical to binary search in a 1D array. Time Complexity is O(log(m * n)).

        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        # Store the size of the 2D matrix into memory
        m = len(matrix)
        n = len(matrix[0])

        # Store two pointers to iterate through
        first = 0
        last = m * n - 1
        # Iterate through the 2D matrix
        while first <= last:
            middle = (first + last) // 2
            row = (middle) // n
            col = (middle) % n
            if matrix[row][col] > target:
                last = middle - 1
            elif matrix[row][col] < target:
                first = middle + 1
            else:
                return True
        return False
