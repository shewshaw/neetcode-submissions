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
    void dfs(TreeNode* root, int& depth, int h) {
        if(!root) return;
        depth = max(depth,h);
        dfs(root->left,depth,h+1);
        dfs(root->right,depth,h+1);
    }

    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int depth = 0;
        dfs(root,depth,1);
        return depth;
    }
};
