// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int maxDistinctNum(int arr[], int n, int k);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i,k;
	cin>>n>>k;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	cout <<maxDistinctNum(arr, n, k)<<"\n";
	  }
	return 0;
}
// } Driver Code Ends

struct node {
    int val, cnt;
    node(int val, int cnt):val(val), cnt(cnt) {}
};
class minComp {
    public:
    bool operator()(node a, node b) {
        return a.cnt < b.cnt;
    }
};
int maxDistinctNum(int arr[], int n, int k)
{
	// Complete the function
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
	    mp[arr[i]]++;
	}
	priority_queue<node, vector<node>, minComp> minHeap;
	int ans = mp.size();
	for (auto a : mp) {
	    minHeap.push(node(a.first, a.second));
	}
	while (!minHeap.empty()) {
	    int count = minHeap.top().cnt;
	    minHeap.pop();
	    if (k <= count - 1) {
	        k = 0;
	        break;
	    }
	    k = k - (count - 1);
	}
	if (k) ans -= k; 
	return ans;
}
