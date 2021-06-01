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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int sz = preorder.size();
        if( sz > 1)
        {
            for(int i = 1; i < sz; i++)
            {
                insertToBST(root,preorder[i]);
            }
        }
        
        return root;
    }
    
    TreeNode* insertToBST(TreeNode* root,int newNode)
    {
        if(!root)
        {
            TreeNode* nn = new TreeNode(newNode);
        
            return nn;
        }
            
        
        if(root->val > newNode)
        {
            
            root->left = insertToBST(root->left,newNode);
            
        }else{
            
            root->right = insertToBST(root->right,newNode);
            
        }
        
        return root;
    }
};