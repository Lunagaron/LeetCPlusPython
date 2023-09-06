class Solution(object):
    def groupAnagrams(self, strs):
        """
        Given an array of strings strs, group the anagrams together.
        You can return the answer in any order. An Anagram is a word
        or phrase formed by rearranging the letters of a different
        word or phrase, typically using all the original letters
        exactly once.

        :type strs: List[str]
        :rtype: List[List[str]]
        """
        myDict = {}

        for words in strs:
            count = [0] * 26

            for word in words:
                count[ord(word) - ord("a")] += 1

            tuple_count = tuple(count)

            if tuple_count not in myDict:
                myDict[tuple_count] = []

            myDict[tuple_count].append(words)

        return list(myDict.values())


class Solution(object):
    def groupAnagrams(self, strs):
        """
        Given an array of strings strs, group the anagrams together.
        You can return the answer in any order. An Anagram is a word
        or phrase formed by rearranging the letters of a different
        word or phrase, typically using all the original letters
        exactly once.

        :type strs: List[str]
        :rtype: List[List[str]]
        """
        myDict = {}

        for word in strs:
            # Sort the characters in each word
            ordered_word = "".join(sorted(word))

            # Hash the sorted characters
            hash_function = hash(ordered_word)

            # Check if this hash exists in the dictionary
            if hash_function not in myDict:
                myDict[hash_function] = []

            # Append the original word to the appropriate list in the dictionary
            myDict[hash_function].append(word)

        return list(myDict.values())
