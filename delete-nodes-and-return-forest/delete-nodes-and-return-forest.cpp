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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        vector<int> to_delete_new(1001,0);
        preprocessing(to_delete,to_delete_new);
        
        vector<TreeNode*> res;
        
        helper(root,to_delete_new,res);
        
        if(root)
        {
            res.push_back(root);
        }
        
        return res;
    }
    
    void helper(TreeNode* &root, vector<int> &to_delete_new, vector<TreeNode*> &res)
    {
        if(!root)
            return;
        
        
        helper(root->left,to_delete_new,res);
        helper(root->right,to_delete_new,res);
        
        int sz = res.size();
        
        if(to_delete_new[root->val])
        {
            if(root->left)
            {
                res.push_back(root->left);
            }
            
            if(root->right)
            {
                res.push_back(root->right);
            }
            
            root = nullptr;
        }
        
        
    }
    
    
    void preprocessing(vector<int>& to_delete, vector<int>& to_delete_new)
    {
        int sz = to_delete.size();
        for(int i = 0; i < sz ; i++)
        {
            to_delete_new[to_delete[i]]++;
        }
    }
};