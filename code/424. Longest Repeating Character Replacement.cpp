class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        if (n <= k) return n;
        int left = 0;
        int count[26] = {0};
        int mx = 0;
        int ans = 0;
        for (int right = 0; right < n; right++) {
            count[s[right] - 'A']++;
            for (int i = 0; i < 26; i++) mx = max(mx, count[i]);
            while (right - left + 1 - mx > k) {
                count[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};