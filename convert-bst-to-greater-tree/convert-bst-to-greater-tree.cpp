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
    int s = 0;
    TreeNode* convertBST(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if(!root)
            return root;
       
        func(root);
      return root;
    }
    
    void func(TreeNode* root)
    {
        if(root->right)
            func(root->right);
        
        s = root->val = s + root->val;
        
        if(root->left)
            func(root->left);
        
    }
};