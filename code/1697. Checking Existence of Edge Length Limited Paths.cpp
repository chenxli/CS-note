class Solution {
public:
    int father[100005];
    void Init(int n) {
        for (int i = 0; i < n; i++) father[i] = i;
    }
    int Find(int a) {
        int x = a;
        if (father[x] == x) {
            return x;
        } else {
            return father[x] = Find(father[x]);
        }
    }
    void Union(int a, int b) {
        int fa = Find(a), fb = Find(b);
        if (fa == fb) return;
        father[fa] = fb;
    }
    bool isConnected(int a, int b) {
        return Find(a) == Find(b);
    }
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int m = queries.size();
        for (int i = 0; i < queries.size(); i++) queries[i].push_back(i);
        sort(begin(edgeList), end(edgeList), cmp);
        sort(begin(queries), end(queries), cmp);
        
        vector<bool> ans(m);
        
        Init(n);
        int i = 0;
        for (auto& q : queries) {
            while (i < edgeList.size() && edgeList[i][2] < q[2]) Union(edgeList[i][0], edgeList[i++][1]);
            if (isConnected(q[0], q[1])) ans[q[3]] = true;
            else ans[q[3]] = false;
        }
        return ans;
    }
};