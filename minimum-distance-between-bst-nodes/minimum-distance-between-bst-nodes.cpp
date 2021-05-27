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
auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        
        int sz= v.size();
        
        int res = INT_MAX;
        for(int i = 0; i < sz-1; i++)
        {
            if(v[i+1] - v[i] < res)
                res = v[i+1] - v[i];
        }
        return res;
        
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