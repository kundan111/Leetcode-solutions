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
    int goodNodes(TreeNode* root) {
        count(root,root->val);
        return res;
    }
    
    void count(TreeNode* root, int val)
    {
        if(!root)
            
            return;
        if(root->val >= val)
        {
            res++;
        }
        if(root->left)
        {
            count(root->left,max(val,root->left->val));    
        }
        if(root->right)
        {
            count(root->right,max(val,root->right->val));    
        }
        
        
    }
};