class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        // write your code here
        unordered_map<int, vector<int>> mp;
        vector<int> inDeg(numCourses, 0);
        for (auto a : prerequisites) {
            mp[a.second].emplace_back(a.first);
            inDeg[a.first]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0) q.push(i);
        }
        vector<int> ans;
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            ans.emplace_back(temp);
            for (int m : mp[temp]) {
                if (--inDeg[m] == 0) q.push(m);
            }
        }
        if (ans.size() == numCourses) return ans;
        else return {};
    }
};