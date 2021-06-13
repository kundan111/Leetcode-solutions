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
    bool isValidBST(TreeNode* root) {
        
        return BSTUtil(root,LLONG_MIN,LLONG_MAX);
    }
    
    bool BSTUtil(TreeNode* root, long long int mini,long long int maxi)
    {
        if(!root)
            return true;
        return (mini < root->val && root->val < maxi) && BSTUtil(root->left,mini,root->val) && BSTUtil(root->right,root->val,maxi);
    }
};