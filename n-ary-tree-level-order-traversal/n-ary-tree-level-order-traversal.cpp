/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        if(!root)
            return vector<vector<int>>();
        
        vector<vector<int>> res(1000);
        int l = 0;
        levelOrderUtil(root,res,0,l);
        
        l++;
        
        res.resize(l);
        
        
        
        
        return res;
    }
    
    
    void levelOrderUtil(Node* root, vector<vector<int>> &res, int d, int &l)
    {
        if(!root)
            return;
        
        if(d>l)
        {
            l = d;
        }
        
        res[d].push_back(root->val);
        
        for(auto i : root->children)
        {
            levelOrderUtil(i,res,d+1,l);
        }
        
    }
};