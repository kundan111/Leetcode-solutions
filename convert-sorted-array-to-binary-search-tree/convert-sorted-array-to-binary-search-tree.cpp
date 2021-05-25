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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() > 0)
        {
            int sz = nums.size();
            int l = 0;
            int r = sz-1;
            TreeNode* nn = returnRoot(nums,l,r);
            
            return nn;
        }
        return NULL;
    }
    
    TreeNode* returnRoot(vector<int>& nums, int l, int r)
    {
        if( l > r)
            return NULL;
        if(l == r)
        {
            TreeNode* n = new TreeNode(nums[l]);
            return n;
        }
        
        int mid = l + (r-l+1)/2;
        
        TreeNode* newRoot = new TreeNode(nums[mid]);
        
        newRoot->left = returnRoot(nums,l,mid-1);
        newRoot->right = returnRoot(nums,mid+1,r);
        
        return newRoot;
        
    }
};