class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        anagram_dict = {}
        if len(s) != len(t):
            return False
        # Uploads all characters of string s into dictionary
        for char in s:
            if char not in anagram_dict:
                anagram_dict[char] = 1
            else:
                anagram_dict[char] += 1
        # Unload all characters of string t from anagram_dict
        for letter in t:
            # If letter was never in there
            if letter not in anagram_dict:
                return False
            elif anagram_dict[letter] <= 0:
                return False
            else:
                anagram_dict[letter] -= 1
        return True
