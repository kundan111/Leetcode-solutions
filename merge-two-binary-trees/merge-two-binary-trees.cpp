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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL)
            return NULL;
        if(root1 && !root2)
            return root1;
        if(!root1 && root2)
            return root2;
        
        int sum = root1->val + root2->val;
        
        
        TreeNode *newRoot = new TreeNode(sum);
        newRoot->left = mergeTrees(root1->left, root2->left);
        newRoot->right = mergeTrees(root1->right, root2->right);
        
        return newRoot;
        
        /*
        
        TreeNode* lt = mergeTrees(root1->left,root2->left);
        TreeNode* rt = mergeTrees(root1->right,root2->right);
        
        
        struct TreeNode *newRoot = &TreeNode(sum,lt,rt);
        
        // auto newTreeNode = &newRoot;
        
        return newRoot;
        */
        
    }
};