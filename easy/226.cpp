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
    TreeNode* invertTree(TreeNode* root) {
        // revursion
        // travers all nodes and swap all children
        // DFS
        if (root == nullptr) return nullptr;

        // swap the children
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = tmp;

        invertTree(root->right);
        invertTree(root->left);

        return root;
    }
};
