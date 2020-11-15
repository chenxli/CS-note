class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = INT_MAX, cur = 0, tot = 0, left = 0, right = 0;
        while (right < nums.size()) {
            while (right < nums.size() && tot < s) {
                tot += nums[right];
                right++;
            } 
            while (left < right && tot >= s) {
                ans = min(ans, right - left);
                tot -= nums[left];
                left++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};