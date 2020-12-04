class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) {
            vector<int> tmp = nums1;
            nums1 = nums2;
            nums2 = tmp;
        }
        if ((m + n) & 1) {
            return helper(nums1, nums2, (m + n) / 2 + 1);
        } else {
            double a = helper(nums1, nums2, (m + n) / 2);
            double b = helper(nums1, nums2, (m + n) / 2 + 1);
            return (a + b) / 2;
        }
    }
    double helper(vector<int> v1, vector<int> v2, int k) {
        if (v1.size() == 0) return v2[k - 1];
        if (v2.size() == 0) return v1[k - 1];
        if (k == 1) {
            return v1[0] <= v2[0] ? v1[0] : v2[0];
        }
        int l = min(k / 2, (int)v1.size());
        int r = k - l;
        if (v1[l - 1] >= v2[r - 1]) {
            v2 = vector<int>(v2.begin() + r, v2.end());
            return helper(v1, v2, k - r);
        } else {
            v1 = vector<int>(v1.begin() + l, v1.end());
            return helper(v1, v2, k - l);
        }
    }
};