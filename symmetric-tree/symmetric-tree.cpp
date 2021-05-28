class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        if(!root->left && !root->right)
                return true;
        if(!root->left || !root->right)
            return false;
        
        return helper(root->left,root->right);
        
    }
    
    bool helper(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;
        if(!root1 || !root2)
            return false;
        if(root1->val != root2->val)
            return false;
        
        return helper(root1->left,root2->right) && helper(root1->right,root2->left);
        
        
        
        
    }
};