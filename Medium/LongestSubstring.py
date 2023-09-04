class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        Given a string s, find the length of the longest substring
        without repeating characters.

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

    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Create a dictionary to store character-index pairs
        char_index = {}
        # Initialise variables to 0
        longest = 0
        start = 0
        for index, character in enumerate(s):
            # If the character has already been seen, and is within consideration from the start
            if character in char_index and char_index[character] >= start:
                # Update new start
                start = char_index[character] + 1
            # Update latest location for the character
            char_index[character] = index
            # Finds the longest possible substring at the moment
            longest = max(longest, index - start + 1)
        return longest
