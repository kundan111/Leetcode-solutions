/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original)
            return NULL;
        if(original == target)
        {
            return cloned;
        }
        
        TreeNode* f1 = getTargetCopy(original->left,cloned->left,target);
        TreeNode* f2 = getTargetCopy(original->right,cloned->right,target);
        
       return !( f1 || f2 ) ? NULL:(f1 ? f1 : f2);
        
    }

};