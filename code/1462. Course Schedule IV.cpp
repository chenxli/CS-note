//floyd闭包算法的应用
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pr, vector<vector<int>>& queries) {
        int g[105][105];
        for (int i = 0; i < 105; i++) {
            for (int j = 0; j < 105; j++) {
                g[i][j] = 0;
            }
        }
        for (auto p : pr) {
            int a = p[0], b = p[1];
            g[a][b] = 1;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                if (i == k) continue;
                for (int j = 0; j < n; j++) {
                    if (i == j || j == k || g[i][j]) continue;
                    if (g[i][k] && g[k][j]) g[i][j] = 1;
                }
            }
        }
        vector<bool> ans;
        for (auto q : queries) {
            int a = q[0], b = q[1];
            if (g[a][b]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};