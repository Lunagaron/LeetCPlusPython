/*
 139. Word Break

 Given a string s and a dictionary of strings wordDict, return true if s can be
 segmented into a space-separated sequence of one or more dictionary words. Note
 that the same word in the dictionary may be reused multiple times in the
 segmentation.

 Example 1:

  Input: s = "applepenapple", wordDict = ["apple","pen"]
  Output: true
  Explanation: Return true because "applepenapple" can be segmented as
  "apple pen apple". Note that you are allowed to reuse a dictionary word.
*/

class Solution {
public:
  // Utilises dynamic programming to mark the ends of substrings part of the
  // dictionary found. This will be used later on to ensure words can be formed
  // before searching for a new substring in the next cell. Time Complexity
  // O(m^2 * n) where m is the length of the string and n is the size of the
  // dictionary.
  bool wordBreak(string s, vector<string> &wordDict) {
    int size = s.size();
    vector<bool> isWord(size + 1, false);
    // Base Case: Words of no length can always be broken down
    isWord[0] = true;
    // Recursive Case: Find words that fit for each word. In order to do so,
    // make sure that the grid before the start of each word is marked True,
    // meaning that words can be split up to that point.
    for (int end = 1; end <= size; end++) {
      for (const string &word : wordDict) {
        int len = word.size();
        int start = end - len;
        if (start >= 0 && isWord[start] && s.substr(start, len) == word) {
          isWord[end] = true;
        }
      }
    }
    return isWord[size];
  }
};