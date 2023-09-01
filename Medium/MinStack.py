class MinStack(object):
    """
    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    Implement the MinStack class:

    MinStack() initializes the stack object.
    void push(int val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.

    You must implement a solution with O(1) time complexity for each function.
    """

    def __init__(self):
        self.stack = []
        self.minVal = []

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.stack.append(val)
        if self.minVal:
            val = min(val, self.minVal[-1])
            self.minVal.append(val)
        else:
            self.minVal.append(val)

    def pop(self):
        """
        :rtype: None
        """
        self.stack.pop()
        self.minVal.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.minVal[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
