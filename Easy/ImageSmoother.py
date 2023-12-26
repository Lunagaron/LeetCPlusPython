from copy import deepcopy


class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        """
        An image smoother is a filter of the size 3 x 3 that can be applied to each
        cell of an image by rounding down the average of the cell and the eight
        surrounding cells (i.e., the average of the nine cells in the blue smoother).
        If one or more of the surrounding cells of a cell is not present, we do not
        consider it in the average (i.e., the average of the four cells in the red
        smoother).
        """
        height = len(img)
        width = len(img[0])
        copy_matrix = deepcopy(img)
        for i in range(height):
            for j in range(width):
                # For cells surrounded by cells
                if (0 < i < height - 1) and (0 < j < width - 1):
                    copy_matrix[i][j] = (
                        img[i - 1][j - 1]
                        + img[i - 1][j]
                        + img[i - 1][j + 1]
                        + img[i][j - 1]
                        + img[i][j]
                        + img[i][j + 1]
                        + img[i + 1][j - 1]
                        + img[i + 1][j]
                        + img[i + 1][j + 1]
                    ) // 9

                # For cells at the left edge with width > 1
                elif (0 < i < height - 1) and j == 0 and width > 1:
                    copy_matrix[i][j] = (
                        img[i][j]
                        + img[i - 1][j]
                        + img[i + 1][j]
                        + img[i][j + 1]
                        + img[i - 1][j + 1]
                        + img[i + 1][j + 1]
                    ) // 6
                # For cells at the left edge with width of 1
                elif (0 < i < height - 1) and j == 0 and width == 1:
                    copy_matrix[i][j] = (img[i][j] + img[i - 1][j] + img[i + 1][j]) // 3

                # For cells at the right edge with width > 1
                elif (0 < i < height - 1) and (j == width - 1) and width > 1:
                    copy_matrix[i][j] = (
                        img[i][j]
                        + img[i - 1][j]
                        + img[i + 1][j]
                        + img[i][j - 1]
                        + img[i - 1][j - 1]
                        + img[i + 1][j - 1]
                    ) // 6
                # For cells at the right edge with width == 1
                elif (0 < i < height - 1) and (j == width - 1) and width == 1:
                    copy_matrix[i][j] = (img[i][j] + img[i - 1][j] + img[i + 1][j]) // 3

                # For cells at the top edge and height > 1
                elif (i == 0) and (0 < j < width - 1) and height > 1:
                    copy_matrix[i][j] = (
                        img[i][j]
                        + img[i][j - 1]
                        + img[i][j + 1]
                        + img[i + 1][j]
                        + img[i + 1][j - 1]
                        + img[i + 1][j + 1]
                    ) // 6
                # For cells at the top edge and height == 1
                elif (i == 0) and (0 < j < width - 1) and height == 1:
                    copy_matrix[i][j] = (img[i][j] + img[i][j - 1] + img[i][j + 1]) // 3

                # For cells at the bottom edge and height > 1
                elif (i == height - 1) and (0 < j < width - 1) and height > 1:
                    copy_matrix[i][j] = (
                        img[i][j]
                        + img[i][j - 1]
                        + img[i][j + 1]
                        + img[i - 1][j]
                        + img[i - 1][j - 1]
                        + img[i - 1][j + 1]
                    ) // 6
                # For cells at the bottom edge and height == 1
                elif (i == height - 1) and (0 < j < width - 1) and height == 1:
                    copy_matrix[i][j] = (img[i][j] + img[i][j - 1] + img[i][j + 1]) // 3
                # Four corner cases
                # Top-left corner
                elif (i == 0) and (j == 0):
                    total = img[0][0]
                    count = 1
                    if width > 1:
                        total += img[0][1]
                        count += 1
                        if height > 1:
                            total += img[1][1]
                            count += 1
                    if height > 1:
                        total += img[1][0]
                        count += 1
                    copy_matrix[0][0] = total // count

                # Top-right corner
                elif (i == 0) and (j == width - 1):
                    total = img[0][width - 1]
                    count = 1
                    if width > 1:
                        total += img[0][width - 2]
                        count += 1
                        if height > 1:
                            total += img[1][width - 2]
                            count += 1
                    if height > 1:
                        total += img[1][width - 1]
                        count += 1
                    copy_matrix[0][width - 1] = total // count

                # Bottom-left corner
                elif (i == height - 1) and (j == 0):
                    total = img[height - 1][0]
                    count = 1
                    if height > 1:
                        total += img[height - 2][0]
                        count += 1
                        if width > 1:
                            total += img[height - 2][1]
                            count += 1
                    if width > 1:
                        total += img[height - 1][1]
                        count += 1
                    copy_matrix[height - 1][0] = total // count

                # Bottom-right corner
                elif (i == height - 1) and (j == width - 1):
                    total = img[height - 1][width - 1]
                    count = 1
                    if height > 1:
                        total += img[height - 2][width - 1]
                        count += 1
                        if width > 1:
                            total += img[height - 2][width - 2]
                            count += 1
                    if width > 1:
                        total += img[height - 1][width - 2]
                        count += 1
                    copy_matrix[height - 1][width - 1] = total // count

        return copy_matrix
