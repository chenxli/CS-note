class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        n = len(A)
        left = 0
        ans = 0
        zero = 0
        for right, val in enumerate(A):
            if val == 0:
                zero += 1
            while zero > K:
                if A[left] == 0:
                    zero -= 1
                left += 1
            ans = max(ans, right - left + 1)
        return ans