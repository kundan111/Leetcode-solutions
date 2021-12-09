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
private:
    unordered_map<int,int>m;
    int sz;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        sz = inorder.size();
        for(int i = 0; i < sz; i++)
        {
            m[inorder[i]] = i;
        }
        
        
        return buildTree(preorder,inorder,0,sz-1,0,sz-1);
                
        
    }
    
    TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int preStart, int preEnd)
    {
        if(inEnd > sz || preEnd > sz || inEnd < inStart || preEnd < preStart)    
        {
            return nullptr;
        }
        
        // create a root node
        
        TreeNode *newRoot = new TreeNode(preorder[preStart]);
        int inRoot = m[newRoot->val];
        int numsLeft = inRoot - inStart;
        
        
        
        newRoot->left = buildTree(preorder,inorder, inStart, inRoot-1, preStart+1,preStart + numsLeft);
        newRoot->right = buildTree(preorder,inorder, inRoot+1, inEnd, preStart + numsLeft + 1,preEnd);
        
        return newRoot;
        
        
        
    }
};