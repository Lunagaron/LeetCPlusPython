from collections import Counter


class Solution(object):
    def numSpecial(self, mat):
        """
        Given an m x n binary matrix mat, return the number of special
        positions in mat.

        A position (i, j) is called special if mat[i][j] == 1 and all
        other elements in row i and column j are 0 (rows and columns
        are 0-indexed).

        :type mat: List[List[int]]
        :rtype: int
        """
        row_len = len(mat)
        col_len = len(mat[0])
        unique_rows = []
        unique_cols = []

        # Loop iterating through all rows, checking if there is a single 1
        for row in range(row_len):
            if sum(mat[row]) == 1:
                unique_rows.append(row)
        for col in range(col_len):
            if sum(mat[row][col] for row in range(row_len)) == 1:
                unique_cols.append(col)

        # Find total number of unique row and col that match criteria
        counter = 0
        for row in unique_rows:
            for col in unique_cols:
                if mat[row][col] == 1:
                    counter += 1
        return counter
