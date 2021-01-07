class Solution:
    def stoneGameVII(self, stones: List[int]) -> int:
        n = len(stones)
        Sum = [0]
        for s in stones:
            Sum.append(Sum[-1] + s)
        v = [[-1 for i in range(n)] for j in range(n)]
        def dp(l, r):
            if l == r:
                return 0
            if v[l][r] != -1:
                return v[l][r]
            
            ans = max(Sum[r + 1] - Sum[l + 1] - dp(l + 1, r), Sum[r] - Sum[l] - dp(l, r - 1))
            v[l][r] = ans
            return v[l][r]
        return dp(0, n - 1)