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
    TreeNode* increasingBST(TreeNode* root) {
        
        vector<int> v;
        inorder(root,v);
        int sz = v.size();
        int i = 1;
        TreeNode* prev = new TreeNode(v[0]);
        TreeNode* finalRoot = prev;
        while(i < sz)
        {
            int cur = v[i];
            TreeNode *nn = new TreeNode(cur);
            prev->right = nn;
            prev = nn;
            i++;
        }
        
        return finalRoot;
        
        
    }
    
    
    void inorder(TreeNode* root, vector<int> &v)
    {
        if(root)
        {
            inorder(root->left,v);
            v.push_back(root->val);
            inorder(root->right,v);
        }
    }
};