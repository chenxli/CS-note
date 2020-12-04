class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) {
            return 0;
        }
        sort(begin(points), end(points), [&](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (points[i][0] <= points[i - 1][1]) {
                points[i][1] = min(points[i][1], points[i - 1][1]);
            } else {
                ans++;
            }
        }
        return ans;
    }
};