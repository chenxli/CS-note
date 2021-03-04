class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int mp[26] = {0};
        int maxCnt = 0, m = 0;
        for (char ch : tasks) {
            mp[ch - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            if (mp[i] > maxCnt) {
                maxCnt = mp[i];
                m = 1;
            } else if (mp[i] == maxCnt) {
                m++;
            }
        }
        return max((int)tasks.size(), (maxCnt - 1) * (n + 1) + m);
    }
};