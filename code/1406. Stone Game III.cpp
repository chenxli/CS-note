//dp[i]表示从i,...,n-1先手比后手能多拿的分数，递推式：dp[i] = max(dp[i], stone[i] - dp[i + 1], stone[i] + stone[i + 1] - dp[i + 2], stone[i] + stone[i + 1] + stone[i + 2] - dp[i + 3])
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> Sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            Sum[i + 1] = Sum[i] + stoneValue[i];
        }
        vector<int> dp(n + 1, -1e9);
        dp[n] = 0; //key!!!!
        for (int i = n - 1; i >= 0; i--) {
            for (int x = 1; x <= 3; x++) {
                if (i + x - 1 >= n) break;
                dp[i] = max(dp[i], Sum[i + x] - Sum[i] - dp[i + x]);
            }
        }
        return dp[0] == 0 ? "Tie" : (dp[0] > 0 ? "Alice" : "Bob");
    }
};