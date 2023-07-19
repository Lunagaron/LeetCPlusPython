/*
  100. Same Tree

  Given the roots of two binary trees p and q, write a function to check if they
  are the same or not. Two binary trees are considered the same if they are
  structurally identical, and the nodes have the same value.

  Example:
  Input: p = [1,2,3], q = [1,2,3]
  Output: true
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right){} *
};

class Solution {
public:
  // Utilises a breadth-first search to iterate through each tree simultaneously
  // and ensure they match. If a mismatch occurs at any point, return false and
  // the overall return will be false. Time Complexity: O(n).
  bool BFS_Search(TreeNode *same, TreeNode *other) {
    if (same == nullptr && other == nullptr) {
      return true;
    }
    if (same == nullptr || other == nullptr || same->val != other->val) {
      return false;
    }
    return BFS_Search(same->left, other->left) &&
           BFS_Search(same->right, other->right);
  }

  bool isSameTree(TreeNode *p, TreeNode *q) { return BFS_Search(p, q); }
};