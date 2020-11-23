class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int idx = 0;
        int last = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] != last) {
                nums[++idx] = nums[i];
                last = nums[idx];
            } 
        }
        return idx + 1;
    }
};