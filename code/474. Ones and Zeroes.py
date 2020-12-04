class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = [[0 for j in range(n + 1)] for i in range(m + 1)]
        def count(s):
            c0, c1 = len(s), 0
            for ch in s:
                if ch == '1':
                    c0 -= 1
                    c1 += 1
            return c0, c1
        for s in strs:
            c0, c1 = count(s)
            for i in range(m, c0 - 1, -1):
                for j in range(n, c1 - 1, -1):
                    dp[i][j] = max(dp[i][j], dp[i - c0][j - c1] + 1)
        return dp[m][n]
        
        