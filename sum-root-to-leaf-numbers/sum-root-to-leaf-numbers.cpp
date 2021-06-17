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
    int ans = 0;
    int sumNumbers(TreeNode* root) {
        helper(root,"");
        return ans;
    }
    
    void helper(TreeNode* root, string s)
    {
        if(!root)
            return;
        s += to_string(root->val);
        helper(root->left,s);
        helper(root->right,s);
        
        if(!root->left && !root->right)
        {
            ans += stoi(s);
        }
        
    }
};