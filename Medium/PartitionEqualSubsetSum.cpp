/*
  416. Partition Equal Subset Sum

  Given an integer array nums, return true if you can partition the array into
  two subsets such that the sum of the elements in both subsets is equal or
  false otherwise.

  Example 1:
  Input: nums = [1,5,11,5]
  Output: true
  Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/

class Solution {
public:
  // Utilises 2D dynamic programming to solve the main question of finding a sum
  // in the array that can add up to a certain value. Time Complexity is O(n *
  // sum) where n is the number of elements in the nums vector and sum is the
  // total sum of the numbers divided by 2, which is reduced to O(n * sum).
  bool canPartition(vector<int> &nums) {
    int size = nums.size();
    // Check if the sum of all the numbers is even (to ensure an equal split)
    int sum = 0;
    for (int i = 0; i < size; i++) {
      sum += nums[i];
    }
    if (sum % 2 != 0) {
      return false;
    }
    // Begin to find a subset that has sum equal to sum / 2. We will employ a 2D
    // dynamic programming solution here with dimensions (size x sum / 2).
    vector<vector<bool>> sumParts(size, vector<bool>((sum / 2) + 1, false));
    // Base Case: Every number can be summed to zero without anything. Also set
    // the first number up as true.
    for (int i = 0; i < size; i++) {
      sumParts[i][0] = true;
    }
    // Recursive Case: Build up the 2D boolean vector with reference to
    // previously achieved sums.
    for (int i = 1; i < size; i++) {
      for (int current_sum = 1; current_sum <= sum / 2; current_sum++) {
        if (current_sum - nums[i] >= 0 &&
            sumParts[i - 1][current_sum - nums[i]]) {
          sumParts[i][current_sum] = true;
        } else {
          sumParts[i][current_sum] = sumParts[i - 1][current_sum];
        }
      }
    }
    return sumParts[size - 1][sum / 2];
  }
};