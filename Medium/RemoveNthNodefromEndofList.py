# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        Given the head of a linked list, remove the nth node from
        the end of the list and return its head.

        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if not head:
            return

        # Create a dummy node to handle edge case of size 1 linked list
        dummy = ListNode(0, head)
        fast = slow = dummy

        for _ in range(n):
            fast = fast.next

        while fast.next:
            fast = fast.next
            slow = slow.next

        slow.next = slow.next.next
        return dummy.next
