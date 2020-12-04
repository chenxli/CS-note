class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string& s : strs) {
            auto [count0, count1] = count(s);
            for (int i = m; i >= count0; i--) {
                for (int j = n; j >= count1; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - count0][j - count1] + 1);
                }
            }
        }
        return dp[m][n];
    }
    pair<int, int> count(string s) {
        int count0 = s.length(), count1 = 0;
        for (char ch : s) {
            if (ch == '1') {
                ++count1;
                --count0;
            }
        }
        return make_pair(count0, count1);
    }
};