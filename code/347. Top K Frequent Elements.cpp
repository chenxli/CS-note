class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (auto a : mp) {
            min_heap.push({a.second, a.first});
            if (min_heap.size() > k) min_heap.pop();
        }
        vector<int> ans;
        while (!min_heap.empty()) {
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};