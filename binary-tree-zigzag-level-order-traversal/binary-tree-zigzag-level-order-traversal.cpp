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
    vector<vector<int>> v;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        helper(root,0);
        
        return v;
    }
    
    void helper(TreeNode* root, int d)
    {
        if(!root)
            return;
        if(d == v.size())
        {
            v.push_back(vector<int>());
        }
        if(d%2)
        {
            v[d].insert(v[d].begin(),root->val);
        }else{
            v[d].push_back(root->val);
        }
        
        helper(root->left,d+1);
        helper(root->right,d+1);
    }
};