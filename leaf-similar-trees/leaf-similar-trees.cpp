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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return true;
        if(!(root1 && root2))
            return false;
        // both the roots are not null
        vector<int>vec1;
        vector<int>vec2;
        
        leafArray(root1,vec1);
        leafArray(root2,vec2);
        
        return vec1 == vec2;
        
    }
    
    void leafArray(TreeNode* root, vector<int> &v)
    {
        if(!root->left && !root->right)
        {
           v.push_back(root->val);
           return;
        }  
        
        if(root->left)
            leafArray(root->left,v);
        if(root->right)
            leafArray(root->right,v);
            
    }
};