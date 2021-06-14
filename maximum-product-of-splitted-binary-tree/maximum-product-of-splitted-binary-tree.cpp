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
    long long int  res = 0;
    int completeTreeSum = 0;
    int maxProduct(TreeNode* root) {
        completeTreeSum = treeSum(root);
        treeSum(root);
        return res% (int)(1e9 + 7);
    }
    
    
    int treeSum(TreeNode* root)
    {
        if(!root)
            return 0;
        long long sum=treeSum(root->left)+treeSum(root->right)+root->val; 
        res=max(res,sum*(completeTreeSum-sum));   

        return sum;
    }
};