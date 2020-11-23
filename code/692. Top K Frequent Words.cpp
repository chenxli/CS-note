class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        // auto cmp = [](pair<string, int>& a, pair<string, int>& b) {
        //     return a.second != b.second ? a.second > b.second : a.first < b.first;
        // };
        priority_queue<pair<int, string>, vector<pair<int, string>>, less<pair<int, string>>> pq;
        for (string w : words) {
            cnt[w]++;
        }
        for (auto a : cnt) {
            pq.push({-a.second, a.first});
            if (pq.size() > k) pq.pop();
        }
        vector<string> ans(k);
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};