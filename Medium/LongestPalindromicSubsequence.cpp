/*
  516. Longest Palindromic Subsequence

  Given a string s, find the longest palindromic subsequence's length in s. A
  subsequence is a sequence that can be derived from another sequence by
  deleting some or no elements without changing the order of the remaining
  elements.

  Example 1:

  Input: s = "bbbab"
  Output: 4
  Explanation: One possible longest palindromic subsequence is "bbbb".
 */

class Solution {
  // Utilises dynamic programming to find the longest subsequence in the string
  // s.The Time Complexity is O(n^2), where n is the number of characters in s.
private:
  int dynamicSolve(vector<vector<int>> &matrix, int i, int j, string &s) {
    // Identify whether there is a continuation for the longest palindrome
    // subsequence.
    // Base case for diagonals of length 1, all letters equal itself.
    if (i == j) {
      return matrix[i][j] = 1;
    }
    // Special case for duplicates in the next layer of diagonals of length 2.
    if (j - i == 1) {
      if (s[i] == s[j]) {
        return matrix[i][j] = 2;
      } else {
        return matrix[i][j] = 1;
      }
    }
    // General case for continuing diagonal layers
    if (s[i] == s[j]) {
      return matrix[i][j] = matrix[i + 1][j - 1] + 2;
    } else {
      return matrix[i][j] = max(matrix[i + 1][j], matrix[i][j - 1]);
    }
  }

public:
  int longestPalindromeSubseq(string s) {
    // Get the length of the palindrome to create the matrix
    int n = s.length();
    // Dynamically create a matrix of integers n x n
    vector<vector<int>> matrix(n, vector<int>(n));
    // Loops through each diagonal set of letters
    for (int i = 0; i < n; i++) {
      for (int j = 0, k = i; k < n; j++, k++) {
        dynamicSolve(matrix, j, k, s);
      }
    }
    // Print out matrix for debugging
    //    for (int i = 0; i < n; i++) {
    //      for (int j = 0; j < n; j++) {
    //        cout << matrix[i][j] << " ";
    //      }
    //      cout << std::endl;
    //    }
    return matrix[0][n - 1];
  }
};