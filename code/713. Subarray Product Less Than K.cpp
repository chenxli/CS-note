class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        long product = 1;
        int l = 0, r = 0;
        int ans = 0;
        while (r < n) {
            product *= nums[r];
            while (l <= r &&  product >= k) {
                product /= nums[l];
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
};