/*
 49. Group Anagrams

  Given an array of strings strs, group the anagrams together. You can return
  the answer in any order. An Anagram is a word or phrase formed by rearranging
  the letters of a different word or phrase, typically using all the original
  letters exactly once.

 Example 1:
  Input: strs = ["eat","tea","tan","ate","nat","bat"]
  Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

class Solution {
public:
  // This algorithm first organises each string by their alphabetical order then
  // uses the sorted letters to form a key in a hash map. It stores the original
  // strings in vectors associated with that key. By doing so, this will group
  // all the anagrams together. At the end, it goes through each and every
  // single group to form a results vector that is returned. The time complexity
  // of this algorithm is O(n k log k), where n is the size of strs and k is the
  // length of the longest word. Sorting each string takes O(k log k),iterating
  // through the strings is O(n), with each step O(k log k), thus giving the
  // overall time complexity of O(n k log k).
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    // Create a hashmap of key-value pairs to store
    std::unordered_map<std::string, std::vector<std::string>> anagramGrouping;
    // Iterate through the characters and hash
    for (auto words : strs) {
      std::string sortedWords = words;
      // Sort the words
      std::sort(sortedWords.begin(), sortedWords.end());
      // Push into the unordered map
      anagramGrouping[sortedWords].push_back(words);
    }

    std::vector<std::vector<string>> groups;
    for (auto hashes : anagramGrouping) {
      // .Second ensures that only the values are being added (not the hash)
      groups.push_back(hashes.second);
    }

    return groups;
  }
};