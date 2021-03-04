class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int mx = *max_element(begin(A), end(A));
        int mn = *min_element(begin(A), end(A));
        int mid = (mx + mn) / 2;
        if (mn + K >= mid && mx - K <= mid) return 0;
        return mx - mn - 2 * K;
    }
};