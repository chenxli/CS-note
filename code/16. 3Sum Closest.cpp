class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int ans = 0, diff = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (i >= 1 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (abs(nums[i] + nums[l] + nums[r] - target) < diff) {
                    diff = abs(nums[i] + nums[l] + nums[r] - target);
                    ans = nums[i] + nums[l] + nums[r];
                    if (diff == 0) break;
                }
                if (nums[i] + nums[l] + nums[r] > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};