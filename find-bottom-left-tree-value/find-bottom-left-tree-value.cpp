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
    int ans;
    int findBottomLeftValue(TreeNode* root) {
        
        if(root && (!root->left && !root->right))
        {
            return root->val;
        }
        
        
        
        int l = 0;
        helper(root,0,l);
        
        return ans;
        
    }
    
    
    void helper(TreeNode* root,int d, int &l)
    {
        if(!root)
            return;
        helper(root->left,d+1,l);
        helper(root->right,d+1,l);
        
        if(d > l)
        {
            l = d;
            ans = root->val;
        }
    }
    
};