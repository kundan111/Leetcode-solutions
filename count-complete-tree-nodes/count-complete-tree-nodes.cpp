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
    int c = 0;
    int countNodes(TreeNode* root) {
        counter(root);
        
        return c;
    }
    
    
    void counter(TreeNode* root)
    {
        if(!root)
            return;
        c++;
        counter(root->left);
        counter(root->right);
    }
    
    
};