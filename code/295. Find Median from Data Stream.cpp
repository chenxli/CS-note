class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> max_hq;
    priority_queue<int, vector<int>, greater<int>> min_hq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (max_hq.size() == min_hq.size()) {
            min_hq.push(num);
            int min = min_hq.top();
            min_hq.pop();
            max_hq.push(min);
        } else {
            max_hq.push(num);
            int max = max_hq.top();
            max_hq.pop();
            min_hq.push(max);
        }
    }
    
    double findMedian() {
        if (max_hq.size() == min_hq.size()) return (max_hq.top() + min_hq.top()) / 2.0;
        else return max_hq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */