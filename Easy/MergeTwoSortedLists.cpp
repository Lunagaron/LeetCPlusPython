/*
  21. Merge Two Sorted Lists

  You are given the heads of two sorted linked lists list1 and list2. Merge the
  two lists in a one sorted list. The list should be made by splicing together
  the nodes of the first two lists. Return the head of the merged linked list.

  Example 1:
  Input: list1 = [1,2,4], list2 = [1,3,4]
  Output: [1,1,2,3,4,4]
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
  // Iterate through each listNode and append the smallest one onto the final
  // result ListNode. Time Complexity O(n)
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    // Create a new ListNode, keeping a pointer to the start and one to iterate
    ListNode *merged = new ListNode();
    ListNode *current = merged;
    // While not at the end of either ListNode
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val < list2->val) {
        current->next = list1;
        list1 = list1->next;
      } else {
        current->next = list2;
        list2 = list2->next;
      }
      current = current->next;
    }
    // Adding on the remaining entries of ListNode
    while (list1 != nullptr) {
      current->next = list1;
      list1 = list1->next;
      current = current->next;
    }
    // Adding on the remaining entries of ListNode
    while (list2 != nullptr) {
      current->next = list2;
      list2 = list2->next;
      current = current->next;
    }
    return merged->next;
  }
};