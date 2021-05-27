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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        string s = "";
        
        treePath(root,v,s);
        
        return v;
    }
    
    void treePath(TreeNode* root, vector<string> &v, string s)
    {
        if(!root->left && !root->right)
        {
            s = s + to_string(root->val);
            v.push_back(s);
            return;
        }
        
        if(root->left)
        {
            treePath(root->left,v,s + to_string(root->val) + "->");
        }
        if(root->right)
        {
            treePath(root->right,v,s + to_string(root->val) + "->");
        }
        
        
    }
};