class Solution:
    def frequencySort(self, s: str) -> str:
        count = collections.Counter(s)
        lst = sorted(count.items(), key=lambda x : x[1], reverse=True)
        return ''.join([a[0] * a[1] for a in lst])