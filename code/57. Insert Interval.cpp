class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if (n == 0) return {newInterval};
        int left = -1, right = -1;
        vector<vector<int>> ans;
        int i = 0;
        bool hasMerge = false;
        while (i < n) {
            if (!hasMerge) {
                if (intervals[i][1] < newInterval[0]) {
                    ans.push_back(intervals[i]);
                } else if (intervals[i][0] > newInterval[1]) {
                    ans.push_back(newInterval);
                    ans.push_back(intervals[i]);
                    hasMerge = true;
                } else {
                    left = min(intervals[i][0], newInterval[0]);
                    i++;
                    while (i < n && newInterval[1] >= intervals[i][0]) {
                        i++;
                    }
                    right = max(newInterval[1], intervals[i - 1][1]);
                    ans.push_back({left, right});
                    hasMerge = true;
                    continue;
                }
            } else {
                ans.push_back(intervals[i]);
            }
            i++;
        }
        if (!hasMerge) {
            if (newInterval[0] > intervals[n - 1][1]) ans.push_back(newInterval);
            else if (newInterval[1] < intervals[0][0]) ans.insert(begin(ans), newInterval);
        }
        return ans;
    }
};