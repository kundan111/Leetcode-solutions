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
        unordered_map<int,int> m;
        if(!root)
            return false;
        
        preOrder(root,m);
        
        for(auto i = m.begin(); i != m.end(); i++)
        {
            int cur = i->first;
            if(m.find(k-cur) != m.end() && m.find(k-cur) != i)
            {
                return true;
            }
        }
        
        return false;
    }
    
    void preOrder(TreeNode* root,unordered_map<int,int> &m)
    {
        if(root)
        {
            
            
            m[root->val]++;
            preOrder(root->left,m);
            preOrder(root->right,m);
        }
    }
    
    
};