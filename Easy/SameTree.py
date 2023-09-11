# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def isSameTree(self, p, q):
        """
        Given the roots of two binary trees p and q, write a
        function to check if they are the same or not. Two
        binary trees are considered the same if they are
        structurally identical, and the nodes have the same value.

        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """

        def dfs(p, q):
            # If neither node exists (is NULL)
            if not p and not q:
                return True
            # If either node does not exist but the other does
            elif not p or not q:
                return False
            # If there is a node p,q that exists
            else:
                # If the value of p != q
                if p.val != q.val:
                    return False
                else:
                    left = dfs(p.left, q.left)
                    right = dfs(p.right, q.right)
            if left and right:
                return True
            else:
                return False

        return dfs(p, q)
