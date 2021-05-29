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
    bool isBalanced(TreeNode* root) {
        bool res = true;
        helper(root,res);
        
        return res;
    }
    
    int helper(TreeNode* root, bool &res)
    {
        if(!root)
            return 0;
        int l_height = helper(root->left,res);
        int r_height = helper(root->right,res);
        
        if(res)
        {
         res = abs(l_height - r_height) <= 1 ? true : false;   
        }
        
        return 1 + max(l_height,r_height);
    }
};