class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (numbers[l] < numbers[r]) break;
            if (numbers[l] < numbers[mid]) l = mid + 1;
            else if (numbers[mid] < numbers[r]) r = mid;
            else l++;
        }
        return numbers[l];
    }
};