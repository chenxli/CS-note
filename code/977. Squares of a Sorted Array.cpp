class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0, right = n - 1, i = n - 1; 
        while (left <= right) {
            if (nums[left] * nums[left] > nums[right] * nums[right]) {
                ans[i--] = nums[left] * nums[left];
                left++;
            } else {
                ans[i--] = nums[right] * nums[right];
                right--;
            }
        }
        return ans;
        // vector<int> ans;
        // for (int num : nums) {
        //     ans.emplace_back(num * num);
        // }
        // sort(begin(ans), end(ans));
        // return ans;
    }
};