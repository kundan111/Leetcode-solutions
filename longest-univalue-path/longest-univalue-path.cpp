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
    int res = 0;
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return res;
    }
    
    int helper(TreeNode* root)
    {
        if(!root)
            return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        
        int resl = (root->left && root->left->val == root->val) ? ++l : 0;
        int resr = (root->right && root->right->val == root->val) ? ++r : 0;
        
        res = max(res,resl+resr);
        
        return max(resl,resr);
        
    }
    
    /*
    int dfs(TreeNode* node, int& lup) {
        int l = node->left ? dfs(node->left, lup) : 0;
        int r = node->right ? dfs(node->right, lup) : 0;
        int resl = node->left && node->left->val == node->val ? l + 1 : 0;
        int resr = node->right && node->right->val == node->val ? r + 1 : 0;
        lup = max(lup, resl + resr);
        return max(resl, resr);
    }
    */
};