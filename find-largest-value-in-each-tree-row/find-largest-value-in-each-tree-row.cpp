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
    vector <int> largestValues(TreeNode* root) {
        
        if(!root)
        {
            return vector<int>();
        }
        
        vector <int> res(10000,-2147483648);
        
        int l = 0;
        
        helper(root,0,l,res);
        
        l++;
        res.resize(l);
        return res;
    }
    
    void helper(TreeNode* root,int d,int &l , vector<int> &res)
    {
        if(!root)
            return;
        if(d > l)
        {
           l = d; 
        }
        
        if(res[d] < root->val)
        {
            res[d] = root->val;
        }
        
        helper(root->left,d+1,l,res);
        helper(root->right,d+1,l,res);
    }
};