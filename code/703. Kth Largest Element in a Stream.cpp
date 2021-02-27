class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            if (pq.size() < k) pq.push(num);
            else if (pq.top() < num){
                pq.pop();
                pq.push(num);
            }
        }
    }
    
    int add(int val) {
        if (pq.size() < k) pq.push(val);
        else if (pq.top() < val) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */