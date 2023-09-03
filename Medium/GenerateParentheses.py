class Solution(object):
    def generateParenthesis(self, n):
        """
        Given n pairs of parentheses, write a function to generate
        all combinations of well-formed parentheses.

        Example 1:
        Input: n = 3
        Output: ["((()))","(()())","(())()","()(())","()()()"]

        :type n: int
        :rtype: List[str]
        """
        # Initialise array to store solutions
        solution = []

        def recursive(open, close, brackets):
            # End of brackets, a full combination has been made
            if open + close == 2 * n:
                solution.append(brackets)
                return
            # More brackets are still needed to meet n brackets
            if open == close:
                brackets = brackets + "("
                recursive(open + 1, close, brackets)
            else:
                if open < n:
                    brackets1 = brackets + "("
                    recursive(open + 1, close, brackets1)
                brackets2 = brackets + ")"
                recursive(open, close + 1, brackets2)

        recursive(1, 0, "(")
        return solution
