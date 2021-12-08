/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> res1;
        vector<TreeNode*> res2;
        
        pathFinder(root,p->val,res1);
        pathFinder(root,q->val,res2);
        
        /*
        cout << "res1: " ;
        for(int val : res1)
        {
            cout << val << " ";
        }
        cout << endl;
        cout << "res2: " ;
        for(int val : res2)
        {
            cout << val << " ";
        }
        cout << endl;
        
        */
        
        TreeNode* ret = NULL;
        
        int i = 0;
        while(i < res1.size() && i < res2.size() && res1[i] == res2[i])
        {
            ret = res1[i];
            i++;
        }
        
        
        return ret;
        
    }
    
    void pathFinder(TreeNode* root, int target, vector<TreeNode*> &res)
    {
        if(root->val == target)
        {
          res.push_back(root);
          return;
        }else if(root->val > target)
        {
            res.push_back(root);
            pathFinder(root->left,target,res);
        }else{
            res.push_back(root);
            pathFinder(root->right,target,res);
        }
    }
    
    
};