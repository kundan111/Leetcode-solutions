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
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
        {
            return vector<int>();
        }
        
        vector<int> res(101,-1);
        int l = 0;
        helper(root,0,l,res);
        l++;
        res.resize(l);
        
        return res;
    }
    
    void helper(TreeNode* root, int d , int &l, vector<int> &res)
    {
        if(root)
        {
            if(d > l)
            {
                l = d;
            }
            
            res[d] = res[d] == -1 ? root->val : res[d];   
            
            helper(root->right, d+1,l,res);
            helper(root->left,d+1,l,res);
        }
    }
};