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
    int maxDepth(TreeNode* root) {
       if(!root)
          return 0;
        int height = -1;
        
        heightUtil(root,height,1);
        
        return height;
    }
    
    void heightUtil(TreeNode* root, int &height, int temp)
    {
        if(!root)
            return;
        if(height < temp)
            height = temp;
        

        
       heightUtil(root->left,height,temp+1);
      heightUtil(root->right,height,temp+1);
        
    }
};