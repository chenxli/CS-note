class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> Sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            Sum[i + 1] = Sum[i] + stones[i];
        }
        vector<vector<int>> memo(n, vector<int>(n, INT_MAX));
        function<int(int, int)> dp = [&](int l, int r) {
            if (l == r) return memo[l][r] = 0;
            if (memo[l][r] != INT_MAX) return memo[l][r];
            int diff_l = dp(l + 1, r);
            int diff_r = dp(l, r - 1);
            return memo[l][r] = max(Sum[r + 1] - Sum[l + 1] - diff_l, Sum[r] - Sum[l] - diff_r);
        };
        return dp(0, n - 1);
    }
};