/*
 647. Palindromic Substrings

  Given a string s, return the number of palindromic substrings in it. A string
  is a palindrome when it reads the same backward as forward. A substring is a
  contiguous sequence of characters within the string.

  Example 1:
  Input: s = "aaa"
  Output: 6
  Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 */

class Solution {
public:
  // Example of dynamic programming. All smaller palindromes are identified of
  // lengths 1 and 2, and then from 3 on we build on by checking whether the
  // previous substring of length - 2 was also a palindrome and whether the
  // current start and end are the same characters. Time Complexity O(n^2).
  int countSubstrings(string s) {
    int size = s.size();
    int palindrome_counter = 0;
    // Creates a 2D matrix of size x size boolean
    vector<vector<bool>> palindromes(size, vector<bool>(size));
    // Base Case: Each individual letter is a palindrome in and of itself
    for (int i = 0; i < size; i++) {
      // Assign value of 1 palindrome in the string
      palindromes[i][i] = true;
      palindrome_counter++;
    }
    // Base Case: Strings of length 2 if the first and next letters are
    // identical to each other
    for (int i = 0; i < size - 1; i++) {
      if (s[i] == s[i + 1]) {
        palindromes[i][i + 1] = true;
        palindrome_counter++;
      } else {
        palindromes[i][i + 1] = false;
      }
    }
    // Recursive Case: For strings of length 3 and more
    for (int i = 2; i < size; i++) {
      for (int j = 0; j + i < size; j++) {
        if (s[j] == s[i + j] && palindromes[j + 1][i + j - 1] == true) {
          palindromes[j][j + i] = true;
          palindrome_counter++;
        }
      }
    }
    return palindrome_counter;
  }
};