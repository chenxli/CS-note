/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        unordered_map<DirectedGraphNode*, int> inDeg;
        for (auto node : graph) {
            for (auto neighbor : node->neighbors) {
                inDeg[neighbor]++;
            }
        }
        stack<DirectedGraphNode*> st;
        for (auto node : graph) {
            if (inDeg.count(node) == 0) st.push(node);
        }
        vector<DirectedGraphNode*> ans;
        int n = graph.size();
        for (int i = 0; i < n; i++) {
            DirectedGraphNode* node = st.top();
            st.pop();
            ans.push_back(node);
            for (auto neighbor : node->neighbors) {
                if (--inDeg[neighbor] == 0) st.push(neighbor);
            }
        }
        return ans;
    }
};