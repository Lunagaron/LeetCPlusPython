class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        modulo = 10 ** 9 + 7
        # n = number of dice, k = number of faces
        dp = [[0] * (target + 1) for _ in range(n + 1)]

        # Set up base cases for when only one dice is used
        for i in range(min(k, target) + 1):
            dp[1][i] = 1

        # Iterate through the number of dices
        for i in range(2, n + 1):
            # Iterate through the target sum
            for j in range(i, target + 1):
                # Iterate through the dices
                for number in range(1, k + 1):
                    if j - number > 0:
                        dp[i][j] += dp[i - 1][j - number]
                        dp[i][j] %= modulo

        return dp[n][target] % modulo
