class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (1 + n) * n / 2;
        int tot = accumulate(begin(nums), end(nums), 0);
        return sum - tot;
    }
};