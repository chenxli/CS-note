class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) return true;
        unordered_set<int> st;
        while (n != 1) {
            if (st.count(n)) return false;
            st.insert(n);
            n = getSq(n);
        }
        return true;
    }
    int getSq(int n) {
        int res = 0;
        while (n) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
};