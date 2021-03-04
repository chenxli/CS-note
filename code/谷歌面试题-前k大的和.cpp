#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

struct node {
    int val;
    int x, y;
    node(int val, int x, int y) : val(val), x(x), y(y) {}
};
class maxComp {
public:
    bool operator()(node a, node b) {
        return a.val < b.val;
    }
};
vector<int> func(vector<int> A, vector<int> B, int k) {
    int n = A.size();
    int m = B.size();
    priority_queue<node, vector<node>, maxComp> maxHeap;
    sort(begin(A), end(A), greater<int>());
    sort(begin(B), end(B), greater<int>());
    maxHeap.push(node(A[0] + B[0], 0, 0));
    vector<int> ans;
    while (ans.size() < k) {
        node temp = maxHeap.top();
        maxHeap.pop();
        ans.emplace_back(temp.val);
        maxHeap.push(node(A[temp.x + 1] + B[temp.y], temp.x + 1, temp.y));
        maxHeap.push(node(A[temp.x] + B[temp.y + 1], temp.x, temp.y + 1));
    }
    return ans;
}
int main() {
    vector<int> A = {1,2,3,7};
    vector<int> B = {4,5,6};
    vector<int> C = func(A, B, 3);
    for (int c : C) cout << c << endl;
    system("pause");
    return 0;
}