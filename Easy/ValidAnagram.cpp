/*
  242. Valid Anagram

  Given two strings s and t, return true if t is an anagram of s, and false
  otherwise. An Anagram is a word or phrase formed by rearranging the letters of
  a different word or phrase, typically using all the original letters exactly
  once.

  Example 1:
  Input: s = "anagram", t = "nagaram"
  Output: true
 */

class Solution {
public:
  // Uses an unordered map to queue all the letters of a word, and count the
  // number of appearances they make. Afterwards, remove one letter at a time
  // from the map, and if a letter usage is negative, return false indicating no
  // match. Time Complexity O(n).
  bool isAnagram(string s, string t) {
    // If words are not the same length, immediately return false.
    if (s.length() != t.length()) {
      return false;
    }
    // Queue all the letters of s into an unordered set
    unordered_map<char, int> words;
    for (char c : s) {
      words[c]++;
    }
    // Dequeue all letters of t, and expect to not go below 0
    for (char c : t) {
      words[c]--;
      if (words[c] < 0) {
        return false;
      }
    }
    return true;
  }
};