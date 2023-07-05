/*
  135: Candy

  There are n children standing in a line. Each child is assigned a rating value
  given in the integer array ratings. You are giving candies to these children
  subjected to the following requirements:

  Each child must have at least one candy. Children with a higher rating get
  more candies than their neighbors. Return the minimum number of candies you
  need to have to distribute the candies to the children.

  Example 1:
  Input: ratings = [1,0,2]
  Output: 5
  Explanation: You can allocate to the first, second and third child with 2, 1,
  2 candies respectively.
 */

class Solution {
public:
  // A forward and backward pass of the entire kids array to make sure all kids
  // have the right amount of candies. The forward pass ensures each kid with a
  // higher rating has more candy, and the backwards pass ensures the opposite.
  // As each pass loops through the entire vector, we have O(2n). Time
  // Complexity O(n).
  int candy(vector<int> &ratings) {
    int size = ratings.size();
    // Create a candies vector of size "size" all initialised to 1
    vector<int> candies(size, 1);
    // Forward pass of the candies array
    for (int i = 1; i < size; i++) {
      if (ratings[i - 1] < ratings[i]) {
        candies[i] = candies[i - 1] + 1;
      }
    }
    // Backward pass of the candies array to fix up candies
    for (int i = size - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1]) {
        candies[i] = max(candies[i], candies[i + 1] + 1);
      }
    }
    // Return sum of vector candies
    return std::accumulate(candies.begin(), candies.end(), 0);
  }
};
