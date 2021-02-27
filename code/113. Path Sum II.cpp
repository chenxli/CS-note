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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        vector<int> v;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int sum) {
            sum += root->val;
            v.push_back(root->val);
            if (root->left == nullptr and root->right == nullptr) {
                if (sum == targetSum) {
                    ans.push_back(v);
                }
                return;
            }
            if (root->left) {
                dfs(root->left, sum);
                v.pop_back();
            }
            if (root->right) {
                dfs(root->right, sum);
                v.pop_back();
            }
        };
        dfs(root, 0);
        return ans;
    }
};