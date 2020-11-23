class Solution {
public:
    int function(vector<int> A, int k) {
        int asc = 0;
        int n = A.size();
        if (A[0] < A[n - 1]) asc = 1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (A[mid] == k) return mid;
            else if (A[mid] > k && asc || (A[mid] < k && !asc)) r = mid - 1;
            else if (A[mid] < k && asc || (A[mid] > k && !asc)) l = mid + 1;
        }
        return -1;
    }
};