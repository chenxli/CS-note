class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n - i; j++) {
                vector<int> v;
                dfs(nums, v, ans, i, j);
            }
        }
        ans.push_back({});
        return ans;
    }
    void dfs(vector<int>& nums, vector<int>& v, vector<vector<int>>& ans, int start, int len) {
        v.push_back(nums[start]);
        len--;
        if (len == 0) {
            ans.push_back(v);
            return;
        }
        for (int i = start + 1; i < nums.size(); i++) {
            dfs(nums, v, ans, i, len);
            v.pop_back();
        }
    }
};