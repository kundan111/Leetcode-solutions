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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        return rangeSumBSTUtil(root,low,high,sum);
    }
    int rangeSumBSTUtil(TreeNode* root, int low, int high, int &sum) {
        if(!root)
            return 0;
        if(low <= root->val && high >= root->val)
        {
            return sum + root->val + rangeSumBSTUtil(root->left,low,high,sum) + rangeSumBSTUtil(root->right,low,high,sum);
            
        }else{
            if(root->val < low)
                return rangeSumBSTUtil(root->right,low,high,sum);
            else
                return rangeSumBSTUtil(root->left,low,high,sum);
            
        }
            
    }
};