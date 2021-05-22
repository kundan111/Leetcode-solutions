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
    int sumRootToLeaf(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int sum = 0;
        string s = "";
        sumAll(root,sum,s);
        
        return sum;
            
    }
    
    long long int sumAll(TreeNode* root, int &sum, string s)
    {
        if(!root)
            return 0;
        if(root->left == NULL && root->right == NULL)
        {
            s = s + intTochar(root->val);
            int decEqv = stoi(s, 0, 2);
            
            sum = sum + decEqv;
            
            return sum;
        }
        
        return sumAll(root->left,sum,s + intTochar(root->val)) + sumAll(root->right,sum,s + intTochar(root->val)); 
    }
    
    char intTochar(int val)
    {
        return val == 1 ? '1' : '0';
    }
};