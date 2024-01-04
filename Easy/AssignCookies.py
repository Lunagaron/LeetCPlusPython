class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        satisfaction = 0
        index = 0
        for i in range(len(s)):
            if index >= len(g):
                return satisfaction
            if s[i] < g[index]:
                continue
            else:
                satisfaction += 1
                index += 1
        return satisfaction
