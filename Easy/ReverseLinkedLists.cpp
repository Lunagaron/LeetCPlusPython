/*
  206. Reverse Linked Lists

  Given the head of a singly linked list, reverse the list, and return the
  reversed list.

  Example 1:
  Input: head = [1,2,3,4,5]
  Output: [5,4,3,2,1]
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  // Reassigns the ->next property of each NodeList as it iterates along. Since
  // it loops through only once, this algorithm has a linear time complexity.
  // Time Complexity O(n).
  ListNode *reverseList(ListNode *head) {
    // Corner case if input list is null or only has one element
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    // Initialise new ListNode to track reversed list, as well as helper
    // pointers to reassign elements
    ListNode *reversed = nullptr;
    ListNode *current = head;
    ListNode *next = nullptr;
    // Reverse the .next value of each linked list
    while (current != nullptr) {
      next = current->next;
      current->next = reversed;
      reversed = current;
      current = next;
    }
    return reversed;
  }
};