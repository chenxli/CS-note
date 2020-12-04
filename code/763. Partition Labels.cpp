class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> last;
        for (int i = 0; i < S.length(); i++) {
            last[S[i]] = i;
        }
        vector<int> ans;
        int end = 0, start = 0;
        for (int i = 0; i < S.length(); i++) {
            end = max(end, last[S[i]]);
            if (end == i) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};