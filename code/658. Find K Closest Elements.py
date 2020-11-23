class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        v = []
        for num in arr:
            v.append((abs(num - x), num))
        heapq.heapify(v)
        ans = [heapq.heappop(v)[1] for _ in range(k)]
        ans.sort()
        return ans