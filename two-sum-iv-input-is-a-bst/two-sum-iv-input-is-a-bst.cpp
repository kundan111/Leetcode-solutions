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
    bool findTarget(TreeNode* root, int k) {
        
        
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int>m;
        inorder(root,m);
        int sz = m.size();
        int i = 0,j = sz-1;
        
        while(i < j)
        {
            if(m[i] + m[j] > k)
            {
                j--;
            }else if(m[i] + m[j] < k)
            {
                i++;
            }else{
                return true;
            }
        }
        
        
        return false;
    }
    
    void inorder(TreeNode* root, vector<int>&m)
    {
        if(!root)
            return;
        inorder(root->left,m);
        m.push_back(root->val);
        inorder(root->right,m);
    }
};