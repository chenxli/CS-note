class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> Sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            Sum[i + 1] = Sum[i] + piles[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int m = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int m = 1;  m <= i || m == 1; m++) {
                for (int x = 1; x <= 2 * m; x++) {
                    if (i + x - 1 >= n) break;
                    dp[i][m] = max(dp[i][m], Sum[n] - Sum[i] - dp[i + x][max(m, x)]);
                }
            }
        }
        return dp[0][1];
    }
};