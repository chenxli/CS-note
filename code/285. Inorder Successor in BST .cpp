// struct TreeNode {
//     int val;
//     TreeNode* left, *right;
//     TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
// };
class Solution {
public:
    TreeNode* successor(TreeNode* root, TreeNode* p) {
        if (root == nullptr || p == nullptr) return nullptr;
        vector<TreeNode*> v;
        inorder(root, v);
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == p) {
                if (i + 1 < v.size()) return v[i + 1];
                else return nullptr;
            }
        }
        return nullptr;
    }
    void inorder(TreeNode* root, vector<TreeNode*>& v) {
        if (root == nullptr) return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
};