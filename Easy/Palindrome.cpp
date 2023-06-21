/*
 9. Palindrome
 Given an integer x, return true if x is a palindrome, and false otherwise.
 Example 1: Input: x = 121
            Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
 */

#include <string>

class Solution {
public:
  // Traditional Solution for-loop with Time Complexity O(n)
  bool isPalindrome(int x) {
    // Converts int to string
    std::string xStr = std::to_string(x);
    int n = xStr.size();
    for (int i = 0; i < n / 2; i++) {
      if (xStr[i] != xStr[n - i - 1]) {
        return false;
      }
    }
    return true;
  }

  // Faster solution using digit comparisons with Time Complexity O(log n)
  bool isPalindrome(int x) {
    // If x is a negative number, or is divisible by 10 (cant have 010)
    if (x < 0 || (x % 10 == 0 && x != 0)) {
      return false;
    }
    // Builds a reversed number of x
    int reversedNumber = 0;
    while (x > reversedNumber) {
      // Extract the last number of x, and add it to reversedNumber
      reversedNumber = (reversedNumber * 10) + (x % 10);
      // Remove that digit from x
      x /= 10;
    }
    // Return whether x is equal to the newly created reversedNumber. If the
    // length of the number is odd, i.e. 12321, x is 12 and reversedNumber is
    // 123, hence /10.
    return x == reversedNumber || x == reversedNumber / 10;
  }
};