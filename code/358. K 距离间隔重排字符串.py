'''
思路:
用堆

先统计每个单词个数
通过个数建立最大堆(从堆中弹出是个数最多的字母)
每次用个数最多的字母组成k个字符
依次循环下去
'''
class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        from collections import Counter
        import heapq
        if k <= 1: return s
        c = Counter(s)
        n = len(s)
        heap = [(-v, k) for k, v in c.items()]
        heapq.heapify(heap)
        res = ""
        while heap:
            tmp = []
            for _ in range(k):
                if not heap:return res if len(res) == n else ""
                num, alp = heapq.heappop(heap)
                num += 1
                res += alp
                if num != 0:
                    tmp.append((num, alp))
            for t in tmp:
                heapq.heappush(heap, t)
        return res