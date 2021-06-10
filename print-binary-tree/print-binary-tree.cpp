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
    vector<vector<string>> printTree(TreeNode* root) {
        int l = 0;
        height(root,l,0);
        
        int r = l + 1;
        int c = pow(2,l+1) - 1;
        
        vector<vector<string>> res( r , vector<string> (c, ""));
        
        int cur_i = 0;
        int cur_j = (c-1)/2;
        
        
        traversal(res,root,cur_i,cur_j,l);
        
        return res;
    }
    
    void height(TreeNode* root, int &l, int d)
    {
        if(!root)
            return;
        
        if(d > l)
        {
            l = d;
        }
        height(root->left,l,d+1);
        height(root->right,l,d+1);
    }
    
    
    void traversal(vector<vector<string>> &res,TreeNode* root , int i , int j, int &l)
    {
        if(!root)
            return;
        res[i][j] +=   to_string(root->val);
        traversal(res,root->left,i+1,j-pow(2,l-i-1),l);
        traversal(res,root->right,i+1,j+pow(2,l-i-1),l);
    }
    
};