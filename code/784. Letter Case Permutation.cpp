class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int n = S.length();
        vector<string> ans;
        string s;
        function<void(int)> dfs = [&](int idx) {
            if (idx == n) {
                ans.push_back(s);
                return;
            }
            s += S[idx];
            dfs(idx + 1);
            s = s.substr(0, idx);
            if (S[idx] >= 'a' and S[idx] <= 'z') {
                s += 'A' + (S[idx] - 'a');
                dfs(idx + 1);
            } else if (S[idx] >= 'A' and S[idx] <= 'Z') {
                s += 'a' + (S[idx] - 'A');
                dfs(idx + 1);
            }
        };
        dfs(0);
        return ans;
    }
};