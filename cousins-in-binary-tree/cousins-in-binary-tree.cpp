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
    
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> v1,v2;
        
        hasPath(root,v1,x);
        hasPath(root,v2,y);
        
        int sz1= v1.size();
        int sz2 = v2.size();
        
        if(sz1 == sz2)
        {
            if(sz1 <= 1)
            {
                return false;
            }
            
            return (v1[sz1-2] != v2[sz2-2]) ? true : false;
            
        }
        
        
        
        return false;
        
    }
    
    bool hasPath(TreeNode* root, vector<int>& arr, int x)
    {
    
        if (!root)
            return false;


        arr.push_back(root->val);    


        if (root->val == x)    
            return true;

        if (hasPath(root->left, arr, x) ||
            hasPath(root->right, arr, x))
            return true;

        arr.pop_back();
        return false;            
    }
    
    void pathFinder(TreeNode* root, int t,vector <int> &v )
    {
        if(root)
        {
            if(root->val == t)
            {
                v.push_back(root->val);
                return;
            }
            
            v.push_back(root->val);
            
            pathFinder(root->left,t,v);
            pathFinder(root->right,t,v);
            
            v.pop_back();
        }
            
        
    }
    
    
};