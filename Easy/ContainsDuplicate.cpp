/*
  217. Contains Duplicate

  Given an integer array nums, return true if any value appears at least twice
  in the array, and return false if every element is distinct.

  Example 1:
  Input: nums = [1,2,3,1]
  Output: true
 */

class Solution {
public:
  // Standard solution iterating through each number and storing the count into
  // a map. If count exceeds 1, return true, otherwise return false. Time
  // Complexity O(n^2).
  bool containsDuplicate(vector<int> &nums) {
    // Initialise a map to look for and store existing numbers
    map<int, int> mapDuplicates;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (mapDuplicates.find(nums[i]) != mapDuplicates.end()) {
        // If the element is already present in the map, it's a duplicate
        return true;
      } else {
        // Insert the element into the map
        mapDuplicates[nums[i]] = 1;
      }
    }
    return false; // No duplicates found
  }

  // Alternative solution: Sort the array and compare each entry with the
  // previous. Time Complexity O(n log n).
  bool containsDuplicate(vector<int> &nums) {
    // Sort the array
    std::sort(nums.begin(), nums.end());

    // Check for duplicates
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1]) {
        return true; // Found a duplicate
      }
    }
    return false; // No duplicates found
  }

  // Alternative solution: Use unordered_set in cpp, which contains a set of
  // unique objects. Check if the length of unordered_set is the same as nums.
  // Time Complexity O(n).
  bool containsDuplicate(vector<int> &nums) {
    // Create the unordered set of integers
    unordered_set<int> uniqueSet;
    for (int num : nums) {
      // Iterates through nums. If a duplicate is found (which takes
      // constant-time average time complexity for insertion, deletion, search).
      if (uniqueSet.count(num) > 0) {
        return true; // Duplicate found
      }
      uniqueSet.insert(num);
    }
    return false; // No duplicates found
  }
};