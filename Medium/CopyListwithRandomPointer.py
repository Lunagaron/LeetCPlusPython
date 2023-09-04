# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random


class PythonSolution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if not head:
            return
        return copy.deepcopy(head)


class Solution(object):
    def copyRandomList(self, head):
        if not head:
            return

        cur = head
        copy_map = {}

        # Saves all Nodes into a hashmap
        while cur:
            newNode = Node(cur.val)
            copy_map[cur] = newNode
            cur = cur.next

        cur = head
        while cur:
            if cur.next:
                copy_map[cur].next = copy_map[cur.next]
            if cur.random:
                copy_map[cur].random = copy_map[cur.random]
            cur = cur.next
        return copy_map[head]
