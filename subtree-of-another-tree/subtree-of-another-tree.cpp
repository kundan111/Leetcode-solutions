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
        
        bool res = false;
        preorder(root,subRoot,res);
        return res;
    }
    
    bool isSame(TreeNode* r1, TreeNode* r2)
    {
        if((r1 && !r2) || (r2 && !r1))
        {
            return false;
        }
        if(!r1 && !r2)
        {
            return true;
        }
        
        return r1->val == r2->val && isSame(r1->left,r2->left) && isSame(r1->right,r2->right);
    }
    
    void preorder(TreeNode* root, TreeNode* subRoot, bool &res)
    {
        if(root)
        {
            if(root->val == subRoot->val)
            {
                if(!res)
                {
                    res = isSame(root,subRoot);    
                }
            }
            preorder(root->left,subRoot,res);
            preorder(root->right,subRoot,res);
        }
    }
    
    
    
};