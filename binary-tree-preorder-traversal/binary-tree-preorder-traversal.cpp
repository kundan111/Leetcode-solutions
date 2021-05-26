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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        
        preOrder(root,v);
        
        return v;
    }
    void preOrder(TreeNode* root, vector<int> &v)
    {
        if(root)
        {
            
            
            v.push_back(root->val);
            preOrder(root->left,v);
            preOrder(root->right,v);
        }
    }
};