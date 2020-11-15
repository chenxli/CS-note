class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        int a = 1e5 + 5;
        for (int i = 0; i < n - 2; i++) {
            if (a == nums[i]) continue;
            a = nums[i];
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[left] + nums[right] + a > 0) {
                    right--;
                } else if (nums[left] + nums[right] + a < 0) {
                    left++;
                } else {
                    ans.push_back({a, nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                }
            }
        }
        return ans;
    }
};