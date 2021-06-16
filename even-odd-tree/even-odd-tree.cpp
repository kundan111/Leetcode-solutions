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
    bool res = true;
    bool isEvenOddTree(TreeNode* root) {
        vector<int>v;
        
        helper(root,0,v);
        
        return res;
    }
    
    void helper(TreeNode* root, int d, vector<int> &v)
    {
        if(!root)
            return;
        
        if(d == v.size())
        {
            if(d % 2 == 0)
            {
                if(root->val % 2 == 0)
                {
                    res = false;
                    return;
                }
            }else{
                if(root->val % 2 == 1)
                {
                    res = false;
                    return;
                }
            }
            
            v.push_back(root->val);
        }else{
            int cur = root-> val;
            if(d % 2 == 0)
            {
                if(cur % 2 == 0)
                {
                    res = false;
                    return;
                }else{
                    if(cur <= v[d])
                    {
                        res = false;
                    return;
                    }
                    v[d] = cur;
                }
            }else{
                if(cur % 2 == 1)
                {
                    res = false;
                    return;
                }else{
                    if(cur >= v[d])
                    {
                        res = false;
                        return;
                    }
                    v[d] = cur;
                }
            }
        }
        
        helper(root->left,d+1,v);
        helper(root->right,d+1,v);
        
        
        
        
    }
        
};