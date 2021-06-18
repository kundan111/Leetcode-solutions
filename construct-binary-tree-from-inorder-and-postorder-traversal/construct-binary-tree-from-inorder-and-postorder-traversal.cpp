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
    unordered_map<int,int>m;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int sz = inorder.size();
        
        for(int i = 0; i < sz; i++)
        {
            m[inorder[i]] = i;
        }
        int c =postorder.size()-1;
        return treeBuilder(inorder,postorder,0,inorder.size()-1,c);
        
    }
    
    TreeNode* treeBuilder(vector<int> inorder, vector<int> postorder, int l ,int r, int &c)
    {
        if(l>r)
            return nullptr;
        
        int ro = postorder[c];
        
        int curRootIndx = m[ro];
        
        TreeNode* root = new TreeNode(ro);
        
        c--;
        
        root->right = treeBuilder(inorder,postorder,curRootIndx+1,r,c);
        root->left = treeBuilder(inorder,postorder,l,curRootIndx-1,c);
        
        
        return root;
        
    }
};