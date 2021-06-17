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
    unordered_map<TreeNode*,int>m;
    int rob(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int robRootAndGrandCildren = root->val;
        
        if(m[root])
            return m.find(root)->second;
        
        if(root->left)
        {
            robRootAndGrandCildren += rob(root->left->left) + rob(root->left->right);
        }
        
        if(root->right)
        {
            robRootAndGrandCildren += rob(root->right->left) + rob(root->right->right);
        }
        
        
         int res =  max(robRootAndGrandCildren,rob(root->left) + rob(root->right));
        
        m[root] = res;
        
        return res;
    
    }
};