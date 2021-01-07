class Solution {
public:
    bool winnerSquareGame(int n) {
        unordered_map<int, bool> mp;
        function<bool(int)> helper = [&](int stones) {
            if (mp.count(stones)) {
                return mp[stones];
            }
            for (int i = sqrt(stones); i >= 1; i--) {
                if (!helper(stones - i * i)) {
                    return mp[stones] = true;
                }
            }
            return mp[stones] = false;
        };
        return helper(n);
    }
};