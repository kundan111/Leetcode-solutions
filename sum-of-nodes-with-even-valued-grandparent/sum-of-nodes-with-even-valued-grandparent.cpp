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
    int sum = 0;
    int sumEvenGrandparent(TreeNode* root) {
        helper(root);
        return sum;
    }
    
    void helper(TreeNode* root)
    {
        if(root)
        {
            if((root->val) % 2 == 0)
            {
                sumCalc(root);
            }
            
            // if(root->left)
            // {
            //     helper(root->left);    
            // }
            // if(root->right)
            // {
            //     helper(root->right);    
            // }
            
            helper(root->left);
            helper(root->right);
        }
        
    }
    
    void sumCalc(TreeNode* root)
    {
        if(root)
        {
            if(root->left)
            {
                TreeNode* l = root->left;
                if(l->left)
                {
                    sum = sum + l->left->val;
                }
                if(l->right)
                {
                    sum = sum + l->right->val;
                }
            }
            if(root->right)
            {
                TreeNode* r = root->right;
                if(r->left)
                {
                    sum = sum + r->left->val;
                }
                if(r->right)
                {
                    sum = sum + r->right->val;
                }
                
            }
        }
    }
    
    
};