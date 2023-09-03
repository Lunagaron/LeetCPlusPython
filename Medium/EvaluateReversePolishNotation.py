class Solution(object):
    def evalRPN(self, tokens):
        """
        You are given an array of strings tokens that represents an arithmetic expression in a
        Reverse Polish Notation. Evaluate the expression. Return an integer that represents the
        value of the expression. Note that:

        The valid operators are '+', '-', '*', and '/'.
        Each operand may be an integer or another expression.
        The division between two integers always truncates toward zero.
        There will not be any division by zero.
        The input represents a valid arithmetic expression in a reverse polish notation.
        The answer and all the intermediate calculations can be represented in a 32-bit integer.

        :type tokens: List[str]
        :rtype: int
        """
        stack = []

        for item in tokens:
            if item in ["+", "-", "*", "/"]:
                # Pop out the operands to be worked on
                num1 = int(stack.pop())
                num2 = int(stack.pop())

                # Apply operations
                if item == "+":
                    stack.append(num2 + num1)
                elif item == "-":
                    stack.append(num2 - num1)
                elif item == "*":
                    stack.append(num2 * num1)
                # Very important distinction to make here:
                # Division of a positive number by a negative number yields different results
                # 10 / -3 = int(-3.333) = -4, however we do NOT want this. The solution is to
                # find the floor, and switch the signs as shown below.
                else:
                    if num2 * num1 >= 0:
                        stack.append(int(num2 / num1))
                    else:
                        stack.append(-(-num2 // num1))
            else:
                stack.append(int(item))
        return stack.pop()
