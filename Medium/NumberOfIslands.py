class Solution(object):
    def numIslands(self, grid):
        """
        Given an m x n 2D binary grid which represents a map of '1's (land) and '0's (water), return the number of
        islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
        You may assume all four edges of the grid are all surrounded by water.
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0
        # Make a copy of grid
        # visited_grid = copy.deepcopy(grid)
        # Get dimensions of grid
        rows = len(grid)
        columns = len(grid[0])
        # Counter for number of islands
        islands_counted = 0

        def findNeighbours(self, grid, row, col, row_size, col_size):
            # Go up
            if 0 < col and grid[row][col - 1] == "1":
                grid[row][col - 1] = "0"
                findNeighbours(self, grid, row, col - 1, row_size, col_size)

            # Go down
            if col < col_size - 1 and grid[row][col + 1] == "1":
                grid[row][col + 1] = "0"
                findNeighbours(self, grid, row, col + 1, row_size, col_size)

            # Go left
            if row > 0 and grid[row - 1][col] == "1":
                grid[row - 1][col] = "0"
                findNeighbours(self, grid, row - 1, col, row_size, col_size)

            # Go right
            if row < row_size - 1 and grid[row + 1][col] == "1":
                grid[row + 1][col] = "0"
                findNeighbours(self, grid, row + 1, col, row_size, col_size)

        # print(f"row: {rows} col: {columns}")
        for i in range(rows):
            for j in range(columns):
                if grid[i][j] == "1":
                    islands_counted += 1
                    findNeighbours(self, grid, i, j, rows, columns)
        return islands_counted

