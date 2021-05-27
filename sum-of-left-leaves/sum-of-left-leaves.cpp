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
    int sumOfLeftLeaves(TreeNode* root) {
        int s = 0;
        leftSum(root,s);
        
        return s;
    }
    
    int leftSum(TreeNode* root, int &s)
    {
        if(!root)
            return 0;
        if(root->left && (root->left->left == NULL && root->left->right == NULL))
        {
            s = s + root->left->val;
            return s + leftSum(root->right,s);
        }
        
        return  leftSum(root->left,s) + leftSum(root->right,s);
    }
};