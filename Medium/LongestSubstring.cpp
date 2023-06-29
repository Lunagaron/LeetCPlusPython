/*
  3. Longest Substring
  Given a string s, find the length of the longest substring without repeating
  characters.
  Example 1:
  Input: s = "abcabcbb"
  Output: 3
  Explanation: The answer is "abc", with the length of 3.
*/
#include <map>

class Solution {
public:
  // Solution iterating through the entire input string s with Time Complexity
  // O(n)
  int lengthOfLongestSubstring(string s) {
    // Creates a map container from standard library mapping chars to ints
    std::map<char, int> char_index;
    int longest = 0;
    int start = 0;
    // Looping through each element in s
    for (int i = 0; i < s.length(); i++) {
      // If the character to be found is in the char_index map and is larger or
      // equal to the start, then the end of the subsequence has been reached
      if (char_index.find(s[i]) != char_index.end() &&
          char_index[s[i]] >= start) {
        start = char_index[s[i]] + 1;
      }
      // Update latest occurrence in the char_index map
      char_index[s[i]] = i;
      longest = max(longest, i - start + 1);
    }
    return longest;
  }
};