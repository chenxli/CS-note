class Solution {
private:
    bool TopologicalSort(unordered_map<char, set<char>>& graph,
                         unordered_map<char, int>& visit_state,
                         char letter, string& result) {
        if (visit_state[letter] == 1) return false;
        if (visit_state[letter] == 2) return true;
        visit_state[letter] = 1;
        result.push_back(letter);
        for (char next : graph[letter]) {
            if (!TopologicalSort(graph, visit_state, next, result)){
                return false;
            }
        }
        visit_state[letter] = 2;
        return true;
    }
    
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        if (words.empty()) return "";
        unordered_map<char, set<char>> graph;
        unordered_map<char, int> indegree;
        for (char c : words[0]) indegree[c] = 0;
        for (size_t i = 0; i < words.size() - 1; ++i) {
            for (char c : words[i + 1]) {
                if (!indegree.count(c)) {
                    indegree[c] = 0;
                }
            }
            size_t j = 0;
            while (j < words[i].size() && j < words[i + 1].size()
                    && words[i][j] == words[i + 1][j]) {
                ++j;
            }
            // Invalid; the longer string with the same prefix
            // comes first.
            if (j == words[i + 1].size()) return "";
            if (j == words[i].size()) continue;
            char src = words[i][j];
            char dst = words[i + 1][j];
            if (graph[src].insert(dst).second) {
                ++indegree[dst];
            }
        }
        // No explict topological relationships.
        // Still valid; returns lexicographically minimum result.
        if (graph.empty()) {
            string result;
            for (const auto& entry : indegree) {
                result.push_back(entry.first);
            }
            sort(result.begin(), result.end());
            return result;
        }
        
        // Collect 0-indegree and positive-outdegree nodes as sources.
        set<char> srcs;
        for (const auto& entry : indegree) {
            char c = entry.first;
            int ind = entry.second;
            if (ind == 0 && !graph[c].empty()) srcs.insert(c);
        }
        // No topo source; cyclic graph. Invalid.
        if (srcs.empty()) return "";
        
        unordered_map<char, int> visit_state;
        string result;
        for (char src : srcs) {
            // Cyclic graph. Invalid.
            if (!TopologicalSort(graph, visit_state, src, result)) {
                return "";
            }
        }
        
        // Insert letters without any topological relationships to the result
        // at a proper position to make the result lexicographically minimum.
        for (const auto& entry : indegree) {
            char c = entry.first;
            int ind = entry.second;
            // No indegrees and no outdegrees <=> no topological relationships
            // with other nodes.
            if (ind == 0 && graph[c].empty()) {
                result.insert(upper_bound(result.begin(), result.end(), c), c);
            }
        }
        return result;
    }
};