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
        vector<vector<int>> result;
        if(!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> v;
            for(int i = 0; i < size; i++) {
                TreeNode* tnode = q.front();
                v.push_back(tnode->val);
                q.pop();
                if(tnode->left) q.push(tnode->left);
                if(tnode->right) q.push(tnode->right);
            }
            result.push_back(v);
        }
        return result;
    }
};
