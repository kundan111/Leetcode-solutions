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
    vector<int> findMode(TreeNode* root) {
        unordered_map <int,int>m;
        int max_count = 0;
        inorder(root,m,max_count);
        
        vector<int> res;
        
        for(auto i = m.begin(); i != m.end(); i++)
        {
            if(i->second == max_count)
            {
                res.push_back(i->first);
            }
        }
        
        
        return res;
    }
    
    void inorder(TreeNode* root, unordered_map <int,int> &m, int &max_count)
    {
        if(root)
        {
            inorder(root->left,m,max_count);
            m[root->val]++;
            if(m[root->val] >= max_count)
            {
                max_count = m[root->val];
            }
            
            inorder(root->right,m,max_count);
        }
    }
};