class Solution {
public:
    struct node {
        int val;
        int x, y;
        node(int val, int x, int y):val(val), x(x), y(y) {}
    };
    class minComp {
        public:
        bool operator() (node a, node b) {
            return a.val > b.val;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = 0;
        priority_queue<node, vector<node>, minComp> minHeap;
        minHeap.push(node(matrix[i][j], i, j));
        vector<int> vis(m * n, 0);
        vis[0] = 1;
        int cnt = 0;
        int ans = -1;
        while (!minHeap.empty()) {
            node temp = minHeap.top();
            //cout << temp.val << " " << temp.x << " " << temp.y << endl;
            minHeap.pop();
            cnt++;
            ans = temp.val;
            if (cnt == k) break;
            if (temp.y + 1 < m && vis[temp.x  * m + temp.y + 1] == 0) {
                minHeap.push(node(matrix[temp.x][temp.y + 1], temp.x, temp.y + 1));
                vis[temp.x  * m + temp.y + 1] = 1;
            }
            if (temp.x + 1 < n && vis[(temp.x + 1) * m + temp.y] == 0) {
                minHeap.push(node(matrix[temp.x + 1][temp.y], temp.x + 1, temp.y));
                vis[(temp.x + 1) * m + temp.y] = 1;
            }
        }
        return ans;
    }
};