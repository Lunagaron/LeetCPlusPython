class Solution(object):
    def partitionString(self, s):
        """
        :type s: str
        :rtype: int
        """
        track_set = []
        counter = 1
        for i in range(len(s)):
            if s[i] not in track_set:
                track_set.append(s[i])
            else:
                counter += 1
                track_set = []
                track_set.append(s[i])
        return counter
