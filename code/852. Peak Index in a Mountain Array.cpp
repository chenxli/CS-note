class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1;
        int mid = -1;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) break;
            else if (arr[mid] > arr[mid - 1]) l = mid;
            else if (arr[mid] > arr[mid + 1]) r = mid;
        }
        return mid;
    }
};