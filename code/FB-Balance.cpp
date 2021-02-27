class Solution {
    public:
    string balance(string s) {
        int n = s.length();
        int l = 0, r = 0;
        string ans;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') l++;
            if (s[i] == ')') r++;
            if (r > l) {
                s[i] = '*';
                r--;
            }
        }
        l = 0;
        r = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') l++;
            if (s[i] == ')') r++;
            if (s[i] == '*') continue;
            if (l > r) {
                s[i] = '*';
                l--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') ans += s[i];
        }
        return ans;
    }
};