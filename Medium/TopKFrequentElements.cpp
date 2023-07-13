/*
  347. Top K Frequent Elements

  Given an integer array nums and an integer k, return the k most frequent
  elements. You may return the answer in any order.

  Example 1:
  Input: nums = [1,1,1,2,2,3], k = 2
  Output: [1,2]
 */
#include <priority_queue>
#include <vector>

using namespace std;

class Solution {
public:
  // Stores each number and their frequency into a map, and then uses a max heap
  // to pop back out the k largest elements. Iterates through the array of
  // length n once O(n), and then creates a max heap of length k with n elements
  // being considered O(n log k). Popping out elements takes O(k log k). Time
  // Complexity O(n * log k)
  vector<int> topKFrequent(vector<int> &nums, int k) {
    // Creates a map to store each number and their frequency
    map<int, int> arrayCount;
    // Populates map with number and frequency
    for (int num : nums) {
      arrayCount[num]++;
    }
    // Creates a priority queue which stores frequency and number
    priority_queue<pair<int, int>> maxHeap;
    for (auto i : arrayCount) {
      maxHeap.push(make_pair(i.second, i.first));
    }
    // Pops back out the k largest numbers back
    vector<int> result;
    // Each while loop decrements k by 1
    while (k-- > 0) {
      // Extracts the top of the heap, saves it into results, and pops off heap
      result.push_back(maxHeap.top().second);
      maxHeap.pop();
    }
    return result;
  }
};
