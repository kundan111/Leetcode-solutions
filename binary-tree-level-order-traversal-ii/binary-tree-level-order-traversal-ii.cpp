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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        level(root,0,res);
        
        
        
        reverse(res.begin(),res.end());
        
        return res;
        
    }
    
    void level(TreeNode* root, int d, vector<vector<int>> &res)
    {
        if(!root)
            return;
        if(d == res.size())
        {
            res.push_back(vector<int>());
        }
        res[d].push_back(root->val);
        level(root->left,d+1,res);
        level(root->right,d+1,res);
    }
};