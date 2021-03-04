class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDeg(numCourses, 0);
        unordered_map<int, vector<int>> mp;
        for (auto p : prerequisites) {
            inDeg[p[0]]++;
            mp[p[1]].emplace_back(p[0]);
        }
        stack<int> st;
        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0) {
                st.push(i);
            }
        }
        int cnt = 0;
        while (!st.empty()) {
            int temp = st.top();
            st.pop();
            cnt++;
            for (int course : mp[temp]) {
                if (--inDeg[course] == 0) st.push(course);
            }
        }
        return cnt == numCourses;
    }
};