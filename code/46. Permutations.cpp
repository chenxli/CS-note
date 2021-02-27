class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return {nums};
        vector<vector<int>> ans;
        vector<int> v;
        vector<int> vis(n, 0);
        function<void(int)> dfs = [&](int cur) {
            if (cur == n) {
                ans.push_back(v);
                return;
            }
            for (int i = 0; i < n; i++) {
                if (vis[i] == 0) {
                    vis[i] = 1;
                    v.push_back(nums[i]);
                    dfs(cur + 1);
                    v.pop_back();
                    vis[i] = 0;
                }
            }
        };
        dfs(0);
        return ans;
    }
};