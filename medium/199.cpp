class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // The rightmost element is the last node at each level
        // BFS
        
        vector<int> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int q_len = q.size();
            for(int i = 0; i < q_len; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if(i == q_len - 1) {
                    res.push_back(node->val);
                }
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
        }

        return res;
    }
};
