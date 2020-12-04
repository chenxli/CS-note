class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        int left = 0;
        int zero = 0;
        int ans = 0;
        for (int right = 0; right < n; right++) {
            if (A[right] == 0) zero++;
            while (zero > K) {
                if (A[left++] == 0) --zero;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};