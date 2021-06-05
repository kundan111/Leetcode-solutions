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
    int maxAncestorDiff(TreeNode* root) {
        
        ios::sync_with_stdio(false);
        
        int res = 0;
        helper(root,root->val,root->val,res);
        
        return res;
        
    }
    
    void helper(TreeNode* root,int mini, int maxi, int &res)
    {
        if(!root)
            return;
         res = max(res,abs(mini-maxi));
         
        
        if(root->left)
        {
            helper(root->left,min(mini,root->left->val), max(maxi, root->left->val),res);
        }
        
        if(root->right)
        {
            helper(root->right,min(mini,root->right->val), max(maxi, root->right->val),res);
        }
    }
};