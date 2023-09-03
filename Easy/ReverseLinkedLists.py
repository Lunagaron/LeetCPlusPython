# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def reverseList(self, head):
        """
        Given the head of a singly linked list, reverse the list,
        and return the reversed list. Both algorithms have time
        complexity of O(n), but the space complexity is vastly
        different.

        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return

        previous = None

        while head is not None:
            newList = ListNode(head.val, previous)
            previous = newList
            head = head.next

        return previous

    def reverseList(self, head):
        """
        Given the head of a singly linked list, reverse the list,
        and return the reversed list.

        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return

        previous = None
        current = head
        while head is not None:
            head = head.next
            current.next = previous
            previous = current
            current = head
        return previous
