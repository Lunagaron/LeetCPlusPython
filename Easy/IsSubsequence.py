class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if s == t:
            return True
        list_s = list(s)
        list_t = list(t)
        index = 0
        for i, j in enumerate(list_t):
            if index == len(list_s):
                return True
            if j == list_s[index]:
                index += 1
            if index == len(list_s):
                return True
        return False
