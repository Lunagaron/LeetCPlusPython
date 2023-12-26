class Solution(object):
    def onesMinusZeros(self, grid):
        """
        2482. Difference Between Ones and Zeros in Row and Column

        You are given a 0-indexed m x n binary matrix grid.

        A 0-indexed m x n difference matrix diff is created with the following procedure:

            Let the number of ones in the ith row be onesRowi.
            Let the number of ones in the jth column be onesColj.
            Let the number of zeros in the ith row be zerosRowi.
            Let the number of zeros in the jth column be zerosColj.
            diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj

        Return the difference matrix diff.

        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        row_len = len(grid)
        col_len = len(grid[0])

        row_ones = []
        col_ones = []

        # Store sum of 1s in each row and column
        for row in range(row_len):
            row_ones.append(sum(grid[row]))
        for col in range(col_len):
            col_ones.append(sum(grid[row][col] for row in range(row_len)))

        diff = [[0 for _ in range(col_len)] for _ in range(row_len)]
        # Final matrix
        for row in range(row_len):
            for col in range(col_len):
                diff[row][col] = (
                    row_ones[row]
                    + col_ones[col]
                    - (row_len - row_ones[row])
                    - (col_len - col_ones[col])
                )
        return diff
