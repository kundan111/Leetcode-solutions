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
// CHUTIYA QUESTION
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(!root)
        {
            TreeNode* nn = new TreeNode(val);
            return nn;
        }
        
        if(val > root->val)
        {
            TreeNode* nn = new TreeNode(val);
            nn->left = root;
            return nn;
        }
        
        root->right = insertIntoMaxTree(root->right,val);
        
        return root;
    }
};