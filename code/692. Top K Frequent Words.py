class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        mp = collections.Counter(words)
        hp = [(-v, k) for k, v in mp.items()]
        heapq.heapify(hp)
        return [heapq.heappop(hp)[1] for _ in range(k)]