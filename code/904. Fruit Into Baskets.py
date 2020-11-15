class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        count = dict()
        left, ans, cnt = 0, 0, 0
        for right in range(len(tree)):
            count[tree[right]] = count.get(tree[right], 0) + 1
            if count[tree[right]] == 1:
                cnt += 1
            while cnt > 2:
                count[tree[left]] -= 1
                if count[tree[left]] == 0:
                    cnt -= 1
                left += 1
            ans = max(right - left + 1, ans)
        return ans