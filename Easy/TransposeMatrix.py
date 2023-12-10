class Solution(object):
    def transpose(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        # Obtain the length and width of the matrix
        row_size = len(matrix)
        col_size = len(matrix[-1])

        # Create a new matrix with correct dimensions
        new_matrix = [[0 for _ in range(row_size)] for _ in range(col_size)]

        # Populate new matrix
        for row in range(row_size):
            for col in range(col_size):
                new_matrix[col][row] = matrix[row][col]
        return new_matrix
