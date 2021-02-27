/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if (node == nullptr) return INT_MAX;
            if (node->left == nullptr and node->right == nullptr) return 1;
            return min(dfs(node->left), dfs(node->right)) + 1;
        };
        return dfs(root);
    }
};