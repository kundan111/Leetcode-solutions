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
    bool isCompleteTree(TreeNode* root) {
         
       queue<TreeNode*> q;
        q.push(root);
        bool end = false;
        
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            
            if(cur)
            {
               if(end)
               {
                   return false;
               }
               q.push(cur->left);
               q.push(cur->right);
            }else{
                end = true;   
            }
        }
        return true;
    }
};