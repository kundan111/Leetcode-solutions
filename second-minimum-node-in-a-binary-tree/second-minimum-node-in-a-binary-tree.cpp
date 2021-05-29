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
    map <int,int> m;
    int findSecondMinimumValue(TreeNode* root) {
        inorder(root);
        // sort(v.begin(),v.end());
        
        if(m.rbegin()->first == m.begin()->first)
        {
            return -1;
        }
        auto i = m.begin();
        i++;
        return i->first;
    }
    
    void inorder(TreeNode* root)
    {
        if(root)
        {
            inorder(root->left);
            m[root->val];
            inorder(root->right);
        }
    }
};