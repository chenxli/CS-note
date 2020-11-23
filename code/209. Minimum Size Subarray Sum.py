class Solution:
    # time: O(n logn) space: O(n)
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        n = len(nums)
        Sum = dict()
        sm = 0
        ans = int(1e9 + 7)
        for i in range(n):
            sm += nums[i]
            Sum[i] = sm
            if sm >= s:
                ans = min(ans, i + 1)
                l, r = 0, i + 1
                while l < r:
                    mid = (l + r) // 2
                    if Sum[mid] > sm - s:
                        r = mid
                    else:
                        l = mid + 1
                ans = min(ans, i - l + 1);
        if ans == 1e9 + 7: 
            return 0
        else:
            return ans
        