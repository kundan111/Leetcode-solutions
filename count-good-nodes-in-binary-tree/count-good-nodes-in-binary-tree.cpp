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
    int goodNodes(TreeNode* root) {
        
        int maxUntilNow = root->val;
        int res = 0;
        helper(root,maxUntilNow,res);
        
        return res;
    }
    
    void helper(TreeNode* root, int maxUntilNow, int &res)
    {
        if(root->val >= maxUntilNow)
        {
            res++;
            maxUntilNow = root->val;
        }
        
        if(root->left)
        {
            helper(root->left,maxUntilNow,res);
        }
        
        if(root->right)
        {
            helper(root->right,maxUntilNow,res);
        }
    }
};