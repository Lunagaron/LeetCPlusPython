/*
  94. Binary Tree Inorder Traversal

  Given the root of a binary tree, return the inorder traversal of its nodes'
  values.

  Example 1:
  Input: root = [1,null,2,3]
  Output: [1,3,2]
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
  // Use Breadth-First Search to print out in-order traversal
  void BFS_search(struct TreeNode *tree, vector<int> &inorderRoots) {
    if (tree == nullptr) {
      return;
    }
    BFS_search(tree->left, inorderRoots);
    inorderRoots.push_back(tree->val);
    BFS_search(tree->right, inorderRoots);
  }
  // Uses Breadth-First Search function above to recursively travel and append
  // the next node for in-order traversal. Time Complexity O(n)
  vector<int> inorderTraversal(TreeNode *root) {
    // Store elements in an array
    vector<int> inorderRoots;
    // Use breadth-first search to traverse the binary tree
    BFS_search(root, inorderRoots);
    return inorderRoots;
  }
  // Alternative quicker solution:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr) {
      return ans;
    }
    inorderTraversal(root->left);
    inorderTraversal(root->right);
    return ans;
  }
};
