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
    int maxi = 0;
    unordered_map<int,int>m;
    int re;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        subTreeSum(root);
        
        vector<int> result;
        
        for(auto i = m.begin(); i != m.end(); i++)
        {
            if(i->second == maxi)
            {
                result.push_back(i->first);    
            }

        }
            
            return result;
        
    }
    
    int subTreeSum(TreeNode* root)
    {
        if(!root)
            return 0;
        int l = subTreeSum(root->left);
        int r = subTreeSum(root->right);
        
        int res = root->val + l + r;
        
        m[res]++;
        
        if(m[res] > maxi)
        {
            re = res;
            maxi = m[res];
            
        }
        
        return res;
        
    }
};