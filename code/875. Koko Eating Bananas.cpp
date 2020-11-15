class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int n = piles.size();
        int r = *max_element(begin(piles), end(piles));
        int l = 1;
        int mid = -1;
        while (l <= r) {
            mid = l + (r - l) / 2;
            int cnt = 0;
            for (int& p : piles) {
                cnt = cnt + p / mid + (p % mid == 0 ? 0 : 1);
            }
            if (l == r) break;
            if (cnt <= H) r = mid;
            else l = mid + 1;
        }
        return mid;
    }
};