/*
  5.  Longest Palindromic Substring

  Given a string s, return the longest palindromic substring in s.

  Example 1:
  Input: s = "babad"
  Output: "bab"
  Explanation: "aba" is also a valid answer.
 */

class Solution {
  // Implementation of Dynamic Programming for this question. Time Complexity
  // O(n^2), where n is the length of the string.
private:
  bool dynamicSolve(vector<vector<bool>> &matrix, int i, int j, string &s) {
    // Identify whether there is a continuation of the longest palindrome
    // Base case for diagonals, all letters are equal itself
    if (i == j) {
      return matrix[i][j] = true;
    }
    // Special case for next layer of diagonals above base case
    if (j - i == 1) {
      if (s[i] == s[j]) {
        return matrix[i][j] = true;
      } else {
        return matrix[i][j] = false;
      }
    }
    // General case for continuing diagonal layers, check if current letters are
    // matched and previous entry (in between) is a palindrome.
    if (s[i] == s[j] && matrix[i + 1][j - 1] == true) {
      return matrix[i][j] = true;
    } else {
      return matrix[i][j] = false;
    }
  }

public:
  string longestPalindrome(string s) {
    // Get the length of the palindrome to create the matrix
    int n = s.length();
    // Dynamically creates a matrix of boolean n x n set to false
    vector<vector<bool>> matrix(n, vector<bool>(n, false));
    // Store most recent palindrome found in a size-2 array
    array<int, 2> maxPalindrome;
    for (int i = 0; i < n; i++) {
      for (int j = 0, k = i; k < n; j++, k++) {
        // Call dynamic function to solve
        dynamicSolve(matrix, j, k, s);
        if (matrix[j][k] == true) {
          maxPalindrome[0] = j;
          maxPalindrome[1] = k;
        }
      }
    }
    // Print out matrix for debugging
    //    for (int i = 0; i < n; i++) {
    //      for (int j = 0; j < n; j++) {
    //        cout << matrix[i][j] << " ";
    //      }
    //      cout << std::endl;
    //    }
    // Get final index of start of palindrome, and the length it goes for
    int index = maxPalindrome[0];
    int length = maxPalindrome[1] - maxPalindrome[0] + 1;
    return s.substr(index, length);
  }
};