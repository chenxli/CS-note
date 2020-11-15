class Solution:
    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        l, r = 1, max(piles)
        k = 0
        while l <= r:
            k = (l + r) // 2
            if l == r:
                break
            hours = 0
            for p in piles:
                hours += p // k
                if p % k:
                    hours += 1
            if hours <= H:
                r = k
            else:
                l = k + 1
        return k
            