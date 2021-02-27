class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> v;
        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }
        for (auto a : mp) {
            v.push_back(make_pair(a.second, a.first));
        }
        sort(rbegin(v), rend(v));
        string ans;
        for (int i = 0; i < v.size(); i++) {
            ans += string(v[i].first, v[i].second);
        }
        return ans;
    }
};