class Solution(object):
    def characterReplacement(self, s, k):
        """
        You are given a string s and an integer k. You can choose any character of the string
        and change it to any other uppercase English character. You can perform this operation
        at most k times. Return the length of the longest substring containing the same letter
        you can get after performing the above operations.

        Input: s = "ABAB", k = 2
        Output: 4
            Explanation: Replace the two 'A's with two 'B's or vice versa.

        :type s: str
        :type k: int
        :rtype: int
        """
        count = {}
        result = 0

        left = 0
        for index in range(len(s)):
            # Gets the count of the character, or 0 if it doesn't exist
            count[s[index]] = 1 + count.get(s[index], 0)
            while index - left + 1 - max(count.values()) > k:
                count[s[left]] -= 1
                left += 1
            result = max(result, index - left + 1)
        return result
