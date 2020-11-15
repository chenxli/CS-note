class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int a[3] = {0};
         for(int i = 0; i < n ; i++)
         {
         	a[nums[i]]++;
         }
         int j;
         for(j = 0; j < a[0]; j++)
         nums[j] = 0;
         for(j = a[0]; j < a[1] + a[0]; j++)
         	nums[j] = 1;
         for(j = a[0]+a[1]; j < n;j++)
         	nums[j] = 2;
    }
};