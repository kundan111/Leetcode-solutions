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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> m;
        bool res = false;
        if(!root)
            return false;
        
        preOrder(root,m, k,res);
        
        return res;
    }
    
    void preOrder(TreeNode* root,unordered_map<int,int> &m, int k, bool &res)
    {
        if(root)
        {
            m[root->val]++;
            
            if(( k - root->val != root->val  && m.find(k-(root->val)) != m.end()) || (k - root->val == root->val &&  m[root->val] > 1))
            {
                res = true;
                return;
            }
            
            preOrder(root->left,m,k,res);    
            
            preOrder(root->right,m,k,res);    
            
        }
    }
    
    
};