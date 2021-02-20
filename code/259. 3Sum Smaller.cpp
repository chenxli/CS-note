class Solution {
    int func(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] < target) {
                    ans += (r - l);
                    break;
                } else {
                    r--;
                }
            }
        }
        return ans;
    }
};