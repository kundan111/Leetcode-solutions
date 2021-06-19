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
    vector<vector<int>> finalRes;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> res;
        f(root,targetSum,res);
        
        return finalRes;
    }
    
    void f(TreeNode* root, int targetSum,vector<int>res)
    {
        if(!root)
            return;
        if(root->val == targetSum && !root->left && !root->right)
        {
            res.push_back(root->val);
            finalRes.push_back(res);
            return;
        }
        
        res.push_back(root->val);
        f(root->left,targetSum-root->val,res);
        f(root->right,targetSum-root->val,res);
        
    }
};