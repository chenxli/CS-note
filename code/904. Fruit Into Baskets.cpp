class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int cnt = 0;
        int left = 0;
        int ans = 0;
        vector<int> count(tree.size(), 0);
        for (int right = 0; right < tree.size(); right++) {
            count[tree[right]]++;
            if (count[tree[right]] == 1) cnt++;
            while (cnt > 2) {
                count[tree[left]]--;
                if (count[tree[left]] == 0) cnt--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};