/*
 2. Add Two Numbers
 You are given two non-empty linked lists representing two non-negative
 integers. The digits are stored in reverse order, and each of their nodes
 contains a single digit. Add the two numbers and return the sum as a linked
 list. You may assume the two numbers do not contain any leading zero, except
 the number 0 itself.
 */

struct ListNode {
  int val;
  ListNode *next;

  // Constructor with value 0, null next ptr
  ListNode() : val(0), next(nullptr) {}

  // Constructor with a single value,  null next ptr
  ListNode(int x) : val(x), next(nullptr) {}

  // Constructor with a value and next ptr
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  // Solution iterating through each linked-list with Time Complexity O()
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *answer = new ListNode();
    // Create a pointer to traverse the answers linked-list
    ListNode *current = answer;

    // Integer for carry-over operations
    int carry = 0;

    // While loop to iterate through linked-lists of l1, l2
    while (l1 != nullptr or l2 != nullptr) {
      // If l1 value is null, equal 0 otherwise equal l1->val
      int value1 = (l1 != nullptr) ? l1->val : 0;
      int value2 = (l2 != nullptr) ? l2->val : 0;
      int sum = value1 + value2 + carry;

      // Add values into the linked-list
      carry = sum / 10;
      current->next = new ListNode(sum % 10);
      current = current->next;

      if (l1 != nullptr) {
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        l2 = l2->next;
      }
    }
    if (carry > 0) {
      current->next = new ListNode(carry);
    }
    return answer->next;
  }
};
