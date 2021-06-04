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
    int maxLevelSum(TreeNode* root) {
        vector<int> v(100,0);
        int levels = 0;
        
        helper(root,v,0, levels);
        
        levels = levels + 1;
        
        int maximum = v[0];
        int res = 0;
        bool flag = false;
        
        for(int i = 0; i < levels; i++)
        {
            if(v[i] > maximum)
            {
                maximum = v[i];
                res = i;
                
            }
            
        }
        
        return res + 1;
        
        
        
    }
    
    void helper(TreeNode* root, vector<int> &v, int d, int &levels)
    {
        if(!root)
            return;
        
        v[d] = v[d] + root->val;
        if(d > levels)
        {
            levels = d;
        }
        helper(root->left,v,d+1,levels);
        helper(root->right,v,d+1,levels);
    }
};