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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if(!root)
            return res;
        
        // vector<int> temp {root->val};
        // res.push_back(temp);
        
        levelOrder(root,res);
        
        return res;
    }
    
    void levelOrder(TreeNode* root, vector<vector<int>> &res)
    {
        queue<TreeNode*> q;
        
 
        // Enqueue Root and initialize height
        q.push(root);
 
        while (q.empty() == false)
        {
            
            int nodeCount = q.size();
            vector<int> temp;
            
            while (nodeCount > 0)
            {
                TreeNode *node = q.front();
                temp.push_back(node->val);
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
                nodeCount--;
            }
            
            res.push_back(temp);
        }
    }
};