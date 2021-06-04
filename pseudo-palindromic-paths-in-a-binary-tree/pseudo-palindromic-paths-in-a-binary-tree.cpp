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
    int res = 0;
    
    int pseudoPalindromicPaths (TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<int> m(10,0);
        f(root,m);

        return res;
    
}
    
    void f(TreeNode* root,vector<int> m)
    {
        if(!root)
            return;
        m[root->val]++;
        f(root->left,m);
        f(root->right,m);

        if(!root->left && !root->right)
        {
            res = isPalindromePermu(m) ? res + 1 : res;    
        }
    }
    
    bool isPalindromePermu(vector<int> m)
    {
        bool oddFound = false;

        for(auto i = 1 ; i < 10 ;i++)
        {
            int count = m[i];
            if(count % 2 == 1)
            {
                if(oddFound)
                {
                    return false;
                }
                oddFound = true;
            }
        }

        return true;
    }
};