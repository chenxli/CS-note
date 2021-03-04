class Solution {
public:
    //划分数组
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(begin(stones), end(stones), 0);
        bitset<3005> f(0);
        f[0] = 1;
        for (int stone : stones) {
            for (int j = 3004; j >= stone; j--) {
                f[j] = f[j] | f[j - stone];
            }
        }
        int ans = 0;
        for (int i = sum / 2; i >= 0; i--) {
            if (f[i]) {
                ans = sum - i - i;
                break;
            }
        }
        return ans;
    }
};