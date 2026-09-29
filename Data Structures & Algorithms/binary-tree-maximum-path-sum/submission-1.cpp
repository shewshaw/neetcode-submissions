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
    int dfs(TreeNode* root, int& max_sum, int sum) {
        if(!root) return 0;
        int left = max(dfs(root->left,max_sum,sum),0);
        int right = max(dfs(root->right,max_sum,sum),0);
        max_sum = max(root->val+left+right, max_sum);
        return root->val + max(left,right);
    }

    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        dfs(root,max_sum,0);
        return max_sum;
    }
};
