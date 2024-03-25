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
    std::pair<int, int> DFS(TreeNode* root) {
        if (!root) return {true, 0};

        auto left = DFS(root->left);
        auto right = DFS(root->right);

        bool balanced = std::abs(left.second - right.second) <= 1;
        int height = 1 + std::max(left.second, right.second);

        return {balanced && left.first && right.first, height};
    }

    bool isBalanced(TreeNode* root) {
        auto result = DFS(root);
        return result.first;
    }
};
