class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            if (nums[abs(num) - 1] < 0) {
                ans = abs(num);
                break;
            }
            nums[abs(num) - 1] = -nums[abs(num) - 1];
        }
        return ans;
    }
};