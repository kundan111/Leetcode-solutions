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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return helper(root,'P',1,depth,val);
    }
    
    TreeNode* helper(TreeNode* root, char dir, int d, int givenDepth, int val)
    {
        if(d == givenDepth)
        {
            TreeNode* nn = new TreeNode(val);
            if(dir == 'P')
            {
                nn->left = root;
                return nn;
            }else if(dir == 'L')
            {
                nn->left = root;
                return nn;
            }else{
                nn->right = root;
                return nn;
            }
        }
        if(!root)
            return nullptr;
        
        root->left = helper(root->left,'L',d+1,givenDepth,val);
        root->right = helper(root->right,'R',d+1,givenDepth,val);
        
        return root;
    }
    
    
};