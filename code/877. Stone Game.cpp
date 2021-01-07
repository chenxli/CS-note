class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        //
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = piles[i];
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] > 0;
        // vector<vector<int>> memo(n, vector<int>(n, 0));
        // function<int(int, int)> dp = [&](int l, int r) {
        //     if (l == r) return memo[l][r] = piles[l];
        //     if (memo[l][r] != 0) return memo[l][r];
        //     return memo[l][r] = max(piles[l] - dp(l + 1, r), piles[r] - dp(l, r - 1));
        // };
        // return dp(0, n - 1) > 0 ? true : false;
    }
};