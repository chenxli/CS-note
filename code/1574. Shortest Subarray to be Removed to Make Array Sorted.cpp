class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        const int n = arr.size();
        if (n <= 1) return 0;
        
        int ans = n - 1;
        // arr[0, i]
        vector<int> left{arr[0]};
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) break;
            left.push_back(arr[i]);
            ans = min(ans, n - 1 - i);
        }
        if (ans == 0) return ans;
        
        //arr[j, N]
        vector<int> right{arr[n - 1]};
        for (int j = n - 2; j > 0; j--) {
            if (arr[j] > arr[j + 1]) break;
            right.push_back(arr[j]);
            ans = min(ans, j);
        }
        if (ans == 1) return ans;
        reverse(begin(right), end(right));
        
        //arr[0,i]...arr[j,n]
        for (int i = 0; i < left.size(); i++) {
            int l = left[i];
            auto it = lower_bound(begin(right), end(right), l);
            if (it == end(right)) break;
            int j = it - begin(right) + (n - right.size());
            ans = min(ans, j - i - 1);
        }
        return ans;
    }
};