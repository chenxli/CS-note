class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<vector<int>> v;
        int n = aliceValues.size();
        for (int i = 0; i < n; i++) {
            v.push_back({aliceValues[i] + bobValues[i], aliceValues[i], bobValues[i]});
        }
        sort(begin(v), end(v), [&](vector<int>& a, vector<int>& b){
            return a[0] > b[0];
        });
        int alice = 0, bob = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                alice += v[i][1];
            } else {
                bob += v[i][2];
            }
        }
        return alice >= bob ? (alice == bob ? 0 : 1) : -1;
    }
};