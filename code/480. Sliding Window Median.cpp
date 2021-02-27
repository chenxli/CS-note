class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return {};
        vector<double> ans;
        multiset<int> st(begin(nums), begin(nums) + k);
        auto mid = next(begin(st), (k - 1) / 2);
        for (int i = k; i <= n; i++) {
            ans.push_back(((double)*mid + *next(mid, (k - 1) % 2)) / 2.0);
            if (i == n) break;
            st.insert(nums[i]);
            if (nums[i] < *mid) mid--;
            if (nums[i - k] <= *mid) mid++;
            st.erase(st.find(nums[i - k])); 
            //st.erase(st.lower_bound(nums[i - k]));
        }
        return ans;
    }
};