# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def isBalanced(self, root):
        """
        Given a binary tree, determine if it is height-balanced.

        :type root: TreeNode
        :rtype: bool
        """
        is_balanced, _ = self.dfs(root)
        return is_balanced

    def dfs(self, root):
        if not root:
            return True, 0

        left_bal, left = self.dfs(root.left)
        right_bal, right = self.dfs(root.right)

        if not left_bal or not right_bal:
            return False, 0

        if abs(left - right) > 1:
            return False, 0

        return True, 1 + max(left, right)
