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
    int result = 0;
    int findTilt(TreeNode* root) {
        
        
        subTreeSum(root);
        
        return result;
    }
    
    int subTreeSum(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int l_sum = subTreeSum(root->left);
        int r_sum = subTreeSum(root->right);
        
        result = result + abs(l_sum - r_sum);
        
        return root->val + l_sum + r_sum;
    }
};