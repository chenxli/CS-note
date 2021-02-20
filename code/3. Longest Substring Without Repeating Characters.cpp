class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0, right = 0;
        int ans = 0, len = 0;
        unordered_map<char, int> mp;
        while (right < n) {
            while (right < n && mp.count(s[right]) == 0) {
                mp[s[right]] = 1;
                right++;
                len++;
            }
            ans = max(len, ans);
            while (left < right && mp.count(s[right])) {
                mp.erase(s[left]);
                left++;
                len--;
            }
        }
        return ans;
    }
};