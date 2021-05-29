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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Both the roots are not null, so not checking
        if(root && subRoot)
        {
            if(root->val == subRoot->val)
            {
                return isSame(root,subRoot)  || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
            }else{
                return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);    
            }
            
            
            
            
        }
            
        return false;
    }
    
    bool isSame(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 && !root2)
            return true;
        if((root1 && !root2) || (root2 && !root1))
            return false;
        return root1->val == root2->val && isSame(root1->left,root2->left) && isSame(root1->right,root2->right);
    }
};