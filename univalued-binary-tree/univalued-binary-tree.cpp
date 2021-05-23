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
    bool isUnivalTree(TreeNode* root) {
        if(root)
        {
            int v = root->val;
            return (root->left ? util(root->left,v) : true) && (root->right ? util(root->right,v): true);
        }
        
        return true;
        
    }
    
    bool util(TreeNode* root, int temp)
    {
        if(!root)
            return true;
        
        return (root->val == temp) && (util(root->left,root->val)) && (util(root->right,root->val));
    }
    
    
};