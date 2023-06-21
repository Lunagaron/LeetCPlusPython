# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        answer = ListNode()
        current = answer
        add_carry = 0
        while (l1 is not None or l2 is not None):
            val1 = l1.val if l1 is not None else 0
            val2 = l2.val if l2 is not None else 0
            sum = val1 + val2 + add_carry
            if sum < 10:
                current.next = ListNode(sum)
                add_carry = 0
            else:
                current.next = ListNode(sum % 10)
                add_carry = 1
            current = current.next
            l1 = l1.next if l1 is not None else None
            l2 = l2.next if l2 is not None else None

        if add_carry == 1:
            current.next = ListNode(1)

        return answer.next
