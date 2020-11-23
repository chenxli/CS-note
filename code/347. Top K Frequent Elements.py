class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = collections.Counter(nums)
        v = [(-v, k) for k, v in mp.items()]
        heapq.heapify(v)
        return [heapq.heappop(v)[1] for _ in range(k)]