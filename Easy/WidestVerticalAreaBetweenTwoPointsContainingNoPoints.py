class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        x_coords = set()
        for i in range(len(points)):
            x_coords.add(points[i][0])
        if len(x_coords) <= 1:
            return 0
        x_coords = list(x_coords)
        x_coords.sort()
        max_width = 0
        for i in range(len(x_coords) - 1):
            # print(f"{x_coords[i]} and {x_coords[i + 1]}")
            if max_width < x_coords[i + 1] - x_coords[i]:
                max_width = x_coords[i + 1] - x_coords[i]
        return max_width
