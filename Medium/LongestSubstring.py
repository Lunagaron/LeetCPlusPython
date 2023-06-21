class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        char_index = {}
        longest = 0
        start = 0
        for i, j in enumerate(s):
            if j in char_index and char_index[j] >= start:
                start = char_index[j] + 1
            char_index[j] = i
            longest = max(longest, i - start + 1)
        return longest
