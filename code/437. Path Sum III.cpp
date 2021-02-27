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
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        int ans = 0;
        ans += pathSum(root->left, sum);
        ans += pathSum(root->right, sum);
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int cur) {
            if (root == nullptr) return;
            cur += root->val;
            if (cur == sum) ans++;
            dfs(root->left, cur);
            dfs(root->right, cur);
        };
        dfs(root, 0);
        return ans;
    }
};