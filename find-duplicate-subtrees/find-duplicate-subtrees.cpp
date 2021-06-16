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
    unordered_map<string,int> m;
    vector<TreeNode*> res;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        helper(root);
        return res;
    }
    
    string helper(TreeNode* root)
    {
        if(!root)
            return "#";
        string s = to_string(root->val) + "," + helper(root->left) + "," + helper(root->right);
        
        if(m.find(s) != m.end())
        {
              m[s]++;  
        }else{
            m[s] = 1;
        }
        
        if(m[s] == 2)
        {
            res.push_back(root);
        }
        
        return s;
    }
};