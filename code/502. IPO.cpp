class Node {
public:
    Node() {}
    Node(int c, int p) : cost(c), profit(p) {}
    int cost;
    int profit;
};

struct minCompare {
    bool operator()(Node n1, Node n2) {
        return n1.cost > n2.cost;
    }
};

struct maxCompare {
    bool operator() (Node n1, Node n2) {
        return n1.profit < n2.profit;
    }
};
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<Node> vec;
        for (int i = 0; i < Profits.size(); i++) {
            vec.push_back(Node(Capital[i], Profits[i]));
        }
        priority_queue<Node, vector<Node>, minCompare> minCost;
        priority_queue<Node, vector<Node>, maxCompare> maxPro;
        for (int i = 0; i < vec.size(); i++) {
            minCost.push(vec[i]);
        }
        for (int i = 0; i < k; i++) {
            while (!minCost.empty() && W >= minCost.top().cost) {
                maxPro.push(minCost.top());
                minCost.pop();
            }
            if (maxPro.empty()) break;
            W += maxPro.top().profit;
            maxPro.pop();
        }
        return W;
    }
};