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
    int maxPathSum(TreeNode* root) {
     
        int res = INT_MIN;
        maxValue(root,res);
        
        return res;
    }
    
    int maxValue(TreeNode* root, int &res)
    {
        if(!root)
        {
            return 0;
        }
        
        int leftVal = max(0,maxValue(root->left,res));
        int rightVal = max(0,maxValue(root->right,res));
        
        int priceNewpath = root->val + leftVal + rightVal;
        
        res = max(priceNewpath, res);
        
        
        return max(leftVal,rightVal) + root->val;
        
    }
};