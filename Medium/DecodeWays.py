class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == '0':
            return 0

        dp = [0] * (len(s) + 1)
        dp[len(s)] = 1

        for i in range(len(s) - 1, -1, -1):
            if s[i] != '0':
                dp[i] = dp[i + 1]
                if i < len(s) - 1 and (s[i] == '1' or (s[i] == '2' and s[i + 1] < '7')):
                    dp[i] += dp[i + 2]
        return dp[0]
