class Solution(object):
    def isValid(self, s):
        """
        Given a string s containing just the characters
        '(', ')', '{', '}', '[' and ']', determine if
        the input string is valid.

        :type s: str
        :rtype: bool
        """
        stack = []
        for element in s:
            if element in ["(", "{", "["]:
                stack.append(element)
            elif element == ")" and stack != []:
                if stack.pop() != "(":
                    return False
            elif element == "}" and stack != []:
                if stack.pop() != "{":
                    return False
            elif element == "]" and stack != []:
                if stack.pop() != "[":
                    return False
            else:
                return False
        if stack != []:
            return False
        return True
