# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def invertTree(self, root):
        """
        Given the root of a binary tree, invert the tree, and return its root.

        :type root: TreeNode
        :rtype: TreeNode
        """
        if root == None:
            return
        if root.left != None or root.right != None:
            temp = root.left
            root.left = root.right
            root.right = temp

        self.invertTree(root.left)
        self.invertTree(root.right)

        return root
