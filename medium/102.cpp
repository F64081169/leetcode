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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {}; 

        queue<TreeNode*> BFS;
        vector<vector<int>> res;
        BFS.push(root);
        
        while (!BFS.empty()) {
            int level_size = BFS.size(); 
            vector<int> level;
            
            for (int i = 0; i < level_size; ++i) {
                TreeNode* front = BFS.front();
                BFS.pop();
                
                level.push_back(front->val); 
                
                if (front->left) BFS.push(front->left);
                if (front->right) BFS.push(front->right);
            }
            
            res.push_back(level); 
        }
        
        return res;
    }
};
