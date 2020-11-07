class Solution:
    def subarraysWithKDistinct(self, A: List[int], K: int) -> int:
        def subarrays(k):
            ans = 0
            i = 0
            count = dict()
            for j in range(len(A)):
                if A[j] not in count.keys():
                    k -= 1
                count[A[j]] = count.get(A[j], 0) + 1
                
                while k < 0:
                    count[A[i]] -= 1
                    if count[A[i]] == 0:
                        del count[A[i]]
                        k += 1
                    i += 1
                ans += j - i + 1
            return ans
        return subarrays(K) - subarrays(K - 1)
                    