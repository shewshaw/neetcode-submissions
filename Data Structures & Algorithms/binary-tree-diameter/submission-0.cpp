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
    int dfs(TreeNode* root, int& diameter) {
        if(!root) return -1;
        int lh = dfs(root->left,diameter) + 1;
        int rh = dfs(root->right,diameter) + 1;
        diameter = max(diameter, lh + rh);
        return max(lh,rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfs(root,diameter);
        return diameter;
    }
};
