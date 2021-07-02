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
    vector<TreeNode*> vec;
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int l = 0;
        int r = vec.size()-1;
        
        return treeBuilder(l,r);
        
    }
    
    TreeNode* treeBuilder(int l, int r)
    {
        if( l > r )
            return nullptr;
        int mid = l + (r-l)/2;
        TreeNode* nn = vec[mid];
        
        nn->left = treeBuilder(l , mid - 1);
        nn->right = treeBuilder(mid + 1,r);
        
        return nn;
    }
    
    
    void inorder(TreeNode* root)
    {
        if(root)
        {
            inorder(root->left);
            vec.push_back(root);
            inorder(root->right);
        }
    }
        
};