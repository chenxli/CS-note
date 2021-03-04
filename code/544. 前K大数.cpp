class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    // int partition(vector<int>& v, int l, int r) {
    //     int pivot = v[r - 1];
    //     int i = l;
    //     for (int j = l; j < r; j++) {
    //         if (v[j] >= pivot) {
    //             swap(v[i], v[j]);
    //             i++;
    //         }
    //     }
    //     return i;
    // }
    vector<int> topk(vector<int> &nums, int k) {
        // write your code here
        int n = nums.size();
        if (k <= 0 || k > n) return {};
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            if (minHeap.size() < k) {
                minHeap.push(num);
            } else if (minHeap.top() < num) {
                minHeap.pop();
                minHeap.push(num);
            }
        }
        vector<int> ans(k);
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = minHeap.top();
            minHeap.pop();
        }
        return ans;
        // int l = 0, r = n;
        // while (l < r) {
        //     int t = partition(nums, l, r);
        //     if (t == k) break;
        //     else if (t < k) {
        //         l = t;
        //     } else if (t > k) {
        //         r = t - 1;
        //     }
        // }
        // return vector<int>(begin(nums), begin(nums) + k);
    }
};