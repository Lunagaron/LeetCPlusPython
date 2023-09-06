class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # Joins lowercased characters if character is alphanumeric
        alpha = "".join(ch.lower() for ch in s if ch.isalnum())
        for pointer in range(len(alpha)):
            ender = len(alpha) - pointer - 1
            while ender > pointer:
                if alpha[ender] != alpha[pointer]:
                    return False
        return True
