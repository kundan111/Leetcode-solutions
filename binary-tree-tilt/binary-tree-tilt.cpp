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
    int findTilt(TreeNode* root) {
        if(!root)
            return 0;
        int res = 0;
        subTreeSum(root,res);
        
        return res;
    }
    
    int subTreeSum(TreeNode* root, int &result)
    {
        if(!root)
            return 0;
        
        int l_sum = subTreeSum(root->left,result);
        int r_sum = subTreeSum(root->right,result);
        
        result = result + abs(l_sum - r_sum);
        
        return root->val + l_sum + r_sum;
    }
};