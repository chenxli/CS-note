class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {
            int idx = abs(num) - 1;
            if (nums[idx] < 0) ans.emplace_back(idx + 1);
            else nums[idx] = -nums[idx];
        }
        return ans;
    }
};