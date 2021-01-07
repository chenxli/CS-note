class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        mp = dict()
        def helper(n):
            if n in mp:
                return mp[n]
            for i in range(int(math.sqrt(n)), 0, -1):
                if not helper(n - i * i):
                    mp[n] = True
                    return mp[n]
            mp[n] = False
            return mp[n]
        return helper(n)