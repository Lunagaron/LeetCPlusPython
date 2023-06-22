# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        # Handle edge cases
        if not list1:
            return list2
        if not list2:
            return list1

        # Merge the two lists
        if list1.val < list2.val:
            merged_head = list1
            list1.next = self.mergeTwoLists(list1.next, list2)
        else:
            merged_head = list2
            list2.next = self.mergeTwoLists(list1, list2.next)

        return merged_head
