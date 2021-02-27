class Solution {
public:
    set<vector<int>> st;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i < n; i++) {
            if (i > 0 and nums[i] == nums[i - 1]) continue;
            for (int j = 1; j <= n - i; j++) {
                vector<int> v;
                dfs(nums, v, i, j);
            }
        }
        vector<vector<int>> ans(begin(st), end(st));
        ans.push_back({});
        return ans;
    }
    void dfs(vector<int>& nums, vector<int> v, int start, int len) {
        v.push_back(nums[start]);
        len--;
        if (len == 0) {
            st.insert(v);
            return;
        }
        for (int i = start + 1; i < nums.size(); i++) {
            dfs(nums, v, i, len);
        }
    }
};