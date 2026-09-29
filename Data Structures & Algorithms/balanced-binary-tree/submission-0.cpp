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
    int dfs(TreeNode* root, bool& balanced) {
        if(!root) return 0;
        int lh = dfs(root->left, balanced) + 1;
        int rh = dfs(root->right, balanced) + 1;
        if(abs(lh-rh) > 1) balanced = false;
        return max(lh,rh);
    }

    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        dfs(root,balanced);
        return balanced;
    }
};
