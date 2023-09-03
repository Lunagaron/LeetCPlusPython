class Solution(object):
    def maxArea(self, height):
        """
        You are given an integer array height of length n. There are n vertical
        lines drawn such that the two endpoints of the ith line are (i, 0) and
        (i, height[i]). Find two lines that together with the x-axis form a container,
        such that the container contains the most water. Return the maximum amount of
        water a container can store. Notice that you may not slant the container.

                :type height: List[int]
                :rtype: int
        """
        # Initialise two pointers, at each end of the container.
        left = 0
        right = len(height) - 1
        width = len(height) - 1
        maxArea = min(height[left], height[right]) * width
        width -= 1

        while left < right:
            # If the limiting height is the left-hand side
            if height[left] < height[right]:
                left += 1
                area = min(height[left], height[right]) * width
                width -= 1
                maxArea = max(area, maxArea)
            # If the limiting height is the right-hand side
            elif height[left] > height[right]:
                right -= 1
                area = min(height[left], height[right]) * width
                width -= 1
                maxArea = max(area, maxArea)
            # If the left and right hand sides are the same height
            else:
                right -= 1
                width -= 1

        return maxArea
