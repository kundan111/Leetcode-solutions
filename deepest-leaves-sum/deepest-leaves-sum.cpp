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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int max_height = 0;
        int lvl = 0;
        
        fun(root,lvl,max_height,sum);
        
        return sum;
        
    }
    
    void fun(TreeNode* root, int lvl, int &max_height, int &sum)
    {
        if(!root)
            return;
        
        if(lvl > max_height && (root->left == NULL && root->right == NULL))
        {
            max_height = lvl;
            sum = root->val;
            return;
        }else if(lvl == max_height && (root->left == NULL && root->right == NULL)){
            max_height = lvl;
            sum = sum + root->val;
            return;
        }
        
        fun(root->left,lvl+1,max_height,sum);
        fun(root->right,lvl+1,max_height,sum);
    }
};