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
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        int ans = 0;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int num) {
            if (root == nullptr) return;
            if (root->left == nullptr and root->right == nullptr) {
                num = num * 10 + root->val;
                ans += num;
                return;
            }
            dfs(root->left, num * 10 + root->val);
            dfs(root->right, num * 10 + root->val);
        };
        dfs(root, 0);
        return ans;
    }
};