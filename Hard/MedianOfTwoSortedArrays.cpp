/*
  4. Median Of Two Sorted Arrays

  Given two sorted arrays nums1 and nums2 of size m and n respectively, return
  the median of the two sorted arrays. The overall run time complexity should be
  O(log (m+n)).

  Example 1:
  Input: nums1 = [1,3], nums2 = [2]
  Output: 2.00000
  Explanation: merged array = [1,2,3] and median is 2.
 */

class Solution {
public:
  // Does NOT solve this in O(log (m+n)) but instead in O(m + n). The logic is
  // to combine both sorted arrays together into an overall array, and find the
  // median as size/2. Time Complexity O(m + n).
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // Iterators for nums1 and nums2
    int i = 0, j = 0;
    vector<int> nums3;
    // While there are elements in both arrays
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] < nums2[j]) {
        nums3.push_back(nums1[i]);
        i++;
      } else {
        nums3.push_back(nums2[j]);
        j++;
      }
    }
    // If there are still elements in nums1
    while (i < nums1.size()) {
      nums3.push_back(nums1[i]);
      i++;
    }
    // If there are still elements in nums2
    while (j < nums2.size()) {
      nums3.push_back(nums2[j]);
      j++;
    }
    // Find the median as middle value if odd or average of the two median
    // values if there are an even number of numbers
    int size = nums3.size();
    if (size % 2 == 0) {
      // if size of nums3 is even, median is average of two middle numbers
      return (nums3[size / 2 - 1] + nums3[size / 2]) / 2.0;
    } else {
      // if size of nums3 is odd, median is the middle number
      return nums3[size / 2];
    }
  }
};
