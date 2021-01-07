#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int m = 0;
        for (int d : data) m ^= d;
        int mask = 1;
        while (m) {
            if (m % 2 == 1) break;
            m /= 2;
            mask = mask << 1;
        }
        cout << mask << endl;
        int a = 0, b = 0;
        for (int d : data) {
            if ((d & mask) != 0) {
                a ^= d;
            } else {
                b ^= d;
            }
        }
        *num1 = a;
        *num2 = b;
    }
};
int main() {
    Solution sol;
    vector<int> data = {2,4,3,6,3,2,5,5};
    int* num1 = new int;
    int* num2 = new int;
    sol.FindNumsAppearOnce(data, num1, num2);
    cout << *num1 << " " << *num2 << endl;
    return 0;
}