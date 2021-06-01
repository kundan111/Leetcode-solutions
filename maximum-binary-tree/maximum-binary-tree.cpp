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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int sz = nums.size();
        int maxIndx = findMaxEleIndx(nums,0,sz-1);
        int l = 0;
        int r = sz-1;
        
        return treeBuilder(nums,0,sz-1,maxIndx,sz);
    
    }
    
    
    
    TreeNode* treeBuilder(vector<int>& nums , int  l  , int r, int maxIndx, int sz)
    {
        if(l > r)
            return NULL;
        if(l==r)
        {
            TreeNode* nn = new TreeNode(nums[l]);
            return nn;
        }
        
        TreeNode* root = new TreeNode(nums[maxIndx]);
        
        int l_maxIndx = findMaxEleIndx(nums, l, maxIndx-1);
        int r_maxIndx = findMaxEleIndx(nums, maxIndx+1,r);

        if(l_maxIndx != -1)
        {
            root->left = treeBuilder(nums,l,maxIndx-1,l_maxIndx,sz);    
        }
        
        if(r_maxIndx != -1)
        {
            root->right = treeBuilder(nums,maxIndx+1,r,r_maxIndx,sz);    
        }
        
        
        return root;
            
    }
    
    
    int findMaxEleIndx(vector<int>nums, int l, int r)
    {
        if( l > r)
            return -1;
        if( l == r)
            return l;
        int maxIndx = l;
        
        
        for(int i = l; i <= r; i++)
        {
                if(nums[i] > nums[maxIndx])
                {
                    maxIndx = i;
                }
        }
        
        return maxIndx;
    }
};