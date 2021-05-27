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
        
        vector <TreeNode*> v1;
        vector <TreeNode*> v2;
        
        pathFinder(root,p,v1);
        pathFinder(root,q,v2);
        
        int counter = 0;
        
        int sz1 = v1.size();
        int sz2 = v2.size();
        
        // bool flag = true;
        while(true)
        {
            if(counter < sz1 && counter < sz2)
            {
                if(v1[counter] == v2[counter])
                {
                    counter++;    
                }else{
                    // flag = false;
                    break;
                }
            }else{
                break;
            }
        }
        
        return  v1[--counter];
        
        
        
    }
    
    void pathFinder(TreeNode* root, TreeNode* t,vector <TreeNode*> &v )
    {
        if(root)
        {
            if(root == t)
            {
                v.push_back(root);
                return;
            }
            
            v.push_back(root);
            
            if(root->val > t->val)
            {
                pathFinder(root->left,t,v);
            }else{
                pathFinder(root->right,t,v);
            }
            
            
            
        }
            
        
    }
};