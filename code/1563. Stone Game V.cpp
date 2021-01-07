class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> Sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            Sum[i + 1] = Sum[i] + stoneValue[i];
        }
        vector<vector<int>> memo(n, vector<int>(n, -1));
        function<int(int, int)> helper = [&](int l, int r) {
            if (l == r) return 0;
            if (memo[l][r] != -1) return memo[l][r];
            int ans = 0;
            for (int i = l + 1; i <= r; i++) {
                int left = Sum[i] - Sum[l];
                int right = Sum[r + 1] - Sum[i];
                if (left < right) {
                    ans = max(ans, left + helper(l, i - 1));
                } else if (left > right) {
                    ans = max(ans, right + helper(i, r));
                } else {
                    ans = max(ans, max(left + helper(l, i - 1), right + helper(i, r)));
                }
            }
            return memo[l][r] = ans;
        };
        return helper(0, n - 1);
    }
};