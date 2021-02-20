class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size(), left = 0, right = n - 1;
        sort(begin(nums), end(nums));
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                ans.push_back({nums[left], nums[right]});
                left++;
                right--;
            } else if (nums[left] + nums[right] > target) {
                right--;
            } else {
                left++;
            }
        }
        return ans;
        // unordered_map<int, int> mp;
        // vector<vector<int>> ans;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (mp.count(target - nums[i])) {
        //         ans.push_back({nums[i], target - nums[i]});
        //         if (--mp[target - nums[i]] == 0) mp.erase(target - nums[i]);
        //     } else {
        //         mp[nums[i]]++;
        //     }
        // }
        // return ans;
    }
};