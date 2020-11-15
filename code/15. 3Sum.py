class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        if n < 3:
            return list()
        nums.sort()
        a = 1e5 + 5
        ans = list()
        for i in range(0, n - 2):
            if a == nums[i]:
                continue
            a = nums[i]
            left = i + 1
            right = n - 1
            while left < right:
                if a + nums[left] + nums[right] > 0:
                    right -= 1
                elif a + nums[left] + nums[right] < 0:
                    left += 1
                else:
                    ans.append([a, nums[left], nums[right]])
                    left += 1
                    right -= 1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
        return ans
        