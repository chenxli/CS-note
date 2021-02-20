class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m = firstList.size(), n = secondList.size();
        if (m == 0 || n == 0) return {};
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while (i < m) {
            if (firstList[i][0] > secondList[j][1]) j++;
            else if (firstList[i][1] < secondList[j][0]) i++;
            else if (firstList[i][1] >= secondList[j][1]) {
                int left = max(firstList[i][0], secondList[j][0]);
                ans.push_back({left, secondList[j][1]});
                j++;
            } else if (firstList[i][0] <= secondList[j][0]) {
                ans.push_back({secondList[j][0], firstList[i][1]});
                i++;
            } else if (firstList[i][0] >= secondList[j][0] && firstList[i][1] <= secondList[j][1]) {
                ans.push_back(firstList[i]);
                i++;
            }
            if (j == n) break;
        }
        return ans;
    }
};