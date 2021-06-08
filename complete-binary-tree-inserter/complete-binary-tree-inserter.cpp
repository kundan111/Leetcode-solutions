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
class CBTInserter {
public:
    TreeNode* curRoot;
    int gItr;
    int sz = 0;
    vector<TreeNode*> res;
    vector<vector<TreeNode*>> temp;
    
    TreeNode* gRoot;
    
    
    CBTInserter(TreeNode* root) {
        gRoot = root;
        levelorder(root,0);
        
        int sz = temp.size();
        for(int i = 0; i < sz; i++)
        {
            vector <TreeNode*> cur = temp[i];
            int j = 0;
            int sz1 = cur.size();
            
            while(j < sz1)
            {
                res.push_back(cur[j]);
                j++;
            }
        }
        
        temp.clear();
        
        int newSz = res.size();
        gItr = newSz - 1;
        
        // set curRoot
        
        curRoot = (newSz % 2 == 0) ? res[(newSz - 2)/2] : res[(newSz - 1)/2];
    }
    
    int insert(int v) {
        
        res.resize(res.size()+1);
        TreeNode* x = new TreeNode(v); 
        
        
        if(!curRoot->left)
        {
            curRoot->left = x;
            
        }else{
            curRoot->right = x;
        }
        
        res[++gItr] = x;
        
        int ret = curRoot->val; 
        
        // set curRoot again
        int newSz = res.size();
        curRoot = (newSz % 2 == 0) ? res[(newSz - 2)/2] : res[(newSz - 1)/2];
        
        return ret;
        
    }
    
    TreeNode* get_root() {
        return gRoot;
    }
    
    void levelorder(TreeNode* root, int level)
    {
        if(!root)
            return;
        if(temp.size() == level)
            temp.push_back(vector<TreeNode*>());
        
        
        
        temp[level].push_back(root);
        levelorder(root->left,level+1);
        levelorder(root->right,level+1);
        
        
    }
    
    
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */