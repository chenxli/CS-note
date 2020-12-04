class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        unordered_map<int, int> memo;
        function<int(int, int)> dp = [&](int i, int j) {
            if (i == 0 || j == 0) return 0;
            if (memo.count(i * n + j)) return memo[i * n + j];
            if (text1[i - 1] == text2[j - 1]) return memo[i *n + j] = dp(i - 1, j - 1) + 1;
            else return memo[i * n + j] = max(dp(i, j - 1), dp(i - 1, j));
        };
        return dp(m, n);
    }
};