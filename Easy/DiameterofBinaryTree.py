# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        Given the root of a binary tree, return the length of the diameter of the tree.
        The diameter of a binary tree is the length of the longest path between any two
        nodes in a tree. This path may or may not pass through the root.

        The length of a path between two nodes is represented by the number of edges between them.
        :type root: TreeNode
        :rtype: int
        """
        return self.helper(root)[1]

    def helper(self, node):
        if node == None:
            return (0, 0)  # Depth and the diameter of the current node
        left_depth, left_diameter = self.helper(node.left)
        right_depth, right_diameter = self.helper(node.right)

        current_depth = 1 + max(left_depth, right_depth)
        current_diameter = max(left_diameter, right_diameter)

        return current_depth, current_diameter
