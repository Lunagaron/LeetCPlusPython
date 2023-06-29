/*
  88. Merge Sorted Array

  You are given two integer arrays nums1 and nums2, sorted in non-decreasing
  order, and two integers m and n, representing the number of elements in nums1
  and nums2 respectively. Merge nums1 and nums2 into a single array sorted in
  non-decreasing order. The final sorted array should not be returned by the
  function, but instead be stored inside the array nums1. To accommodate this,
  nums1 has a length of m + n, where the first m elements denote the elements
  that should be merged, and the last n elements are set to 0 and should be
  ignored. nums2 has a length of n.

  Example 1:

  Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
  Output: [1,2,2,3,5,6]
  Explanation: The arrays we are merging are [1,2,3] and [2,5,6]. The result of
  the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/
#include <vector>

class Solution {
public:
  // Traditional Solution looping through both arrays simultaneously with three
  // pointers, with Time Complexity O(m + n)
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    // Copy of the nums1 vector
    std::vector<int> nums1_copy(nums1);
    // Pointers for referencing elements in vectors
    int i = 0; // For vector nums1_copy
    int j = 0; // For vector nums2
    int k = 0; // For vector nums1

    // While not at the end of either vectors
    while (i < m && j < n) {
      if (nums1_copy[i] <= nums2[j]) {
        nums1[k] = nums1_copy[i];
        i++;
      } else {
        nums1[k] = nums2[j];
        j++;
      }
      k++;
    }

    // Copy remaining elements from nums1_copy if any
    while (i < m) {
      nums1[k] = nums1_copy[i];
      i++;
      k++;
    }

    // Copy remaining elements from nums2 if any
    while (j < n) {
      nums1[k] = nums2[j];
      j++;
      k++;
    }
  }

  // Better memory optimisation, starting from the end of nums1 array (hence no
  // need to create an additional vector). Time Complexity O(m + n)
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    // Initialise three pointers
    int i = m - 1;     // Pointer at the end of nums1 (with numbers)
    int j = n - 1;     // Pointer at the end of nums2
    int k = m + n - 1; // Pointer at the very end of nums1

    // Compare the ends of both pointers
    while (i >= 0 && j >= 0) {
      if (nums1[i] >= nums2[j]) {
        nums1[k] = nums1[i];
        i--;
        k--;
      } else {
        nums1[k] = nums2[j];
        j--;
        k--;
      }
    }
    // If there are any remaining elements inside nums2 vector
    while (j >= 0) {
      nums1[k] = nums2[j];
      j--;
      k--;
    }
  }
};