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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        
        inorder(root1,v1);
        inorder(root2,v2);
        
        int sz1 = v1.size();
        int sz2 = v2.size();
        
        vector<int> res(sz1 + sz2);
        
        int f = 0;
        int s = 0;
        
        int indx = 0;
        while(f < sz1 && s < sz2)
        {
            if(v1[f] < v2[s])
            {
                res[indx++] = v1[f];
                f++;
            }else{
                res[indx++] = v2[s];
                s++;
            }
        }
        
        if(f >= sz1)
        {
            while(s < sz2)
            {
                res[indx++] = v2[s]; 
                s++;
            }
            
        }else{
            while(f < sz1)
            {
                res[indx++] = v1[f]; 
                f++;
            }
        }
        
        return res;
        
    }
    
    
    void inorder(TreeNode* root, vector<int> &v)
    {
        if(root)
        {
            inorder(root->left,v);
            v.push_back(root->val);
            inorder(root->right,v);
        }
    }
};