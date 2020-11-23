class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int i = 0, j = n - 1;
        vector<int> ans;
        int idx = 0;
        while (j - i + 1 > k) {
            if (abs(arr[i] - x) <= abs(arr[j] - x)) {
                j--;
            } else {
                i++;
            }
        }
        for (int u = i; u <= j; u++) {
            ans.push_back(arr[u]);
        }
        return ans;
        // sort(arr.begin(), arr.end(), [&](int a, int b){
        //    return abs(a - x) == abs(b - x) ? a < b : abs(a - x) < abs(b - x);
        // });
        // vector<int> ans;
        // for (int i = 0; i < k; i++) {
        //     ans.push_back(arr[i]);
        // }
        // sort(begin(ans), end(ans));
        // return ans;
    }
};