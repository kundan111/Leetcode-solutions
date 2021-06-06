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
    int ans;
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        bool flag = true;
        helper(root,counter,k,flag);
        
        return ans;
        
    }
    
    void helper(TreeNode* root, int &counter, int k, bool &flag )
    {
        if(root)
        {
            helper(root->left,counter,k , flag);
            counter++;
            if(counter == k && flag)
            {
                ans = root->val;
                flag = false;
            }
            helper(root->right,counter,k,flag);
        }
    }
};