class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum < S or (sum + S) & 1) return 0;
        int p = (sum + S) / 2;
        vector<int> dp(p + 1, 0);
        dp[0] = 1;
        for (int num : nums) {
            for (int i = p; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }
        return dp[p];
    }
};