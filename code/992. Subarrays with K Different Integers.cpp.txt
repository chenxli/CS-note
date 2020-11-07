class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        function<int(int)> subarrays = [&](int k) {
            int n = A.size();
            vector<int> count(n + 1, 0);
            int ans = 0;
            int i = 0;
            for (int j = 0; j < n; j++) {
                if (count[A[j]]++ == 0) {
                    k--;
                }
                while (k < 0) {
                    if (--count[A[i++]] == 0) k++;
                }
                ans += j - i + 1; //以j个元素结尾且元素种类不超过K的子数组个数
            }
            return ans;
        };
        return subarrays(K) - subarrays(K - 1);
    }
};