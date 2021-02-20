class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1 || n == 0) return intervals;
        vector<vector<int>> ans;
        sort(begin(intervals), end(intervals), [&](vector<int> a, vector<int> b){
           return a[0] < b[0]; 
        });
        int i = 1;
        int left = intervals[0][0], right = intervals[0][1];
        while (i < n) {
            if (intervals[i][0] > right) {
                ans.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            } else {
                right = max(right, intervals[i][1]);
            }
            if (i == n - 1) ans.push_back({left, right});
            i++;
        }
        return ans;
    }
};