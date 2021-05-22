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
    vector<int> postorder(Node* root) {
        
        vector<int> res;
        if(!root)
            return res;
        
        postorderUtil(root, res);
        
        return res;
        
    }
    
    void postorderUtil(Node* root, vector<int> &v)
    {
        if(!root)
            return;
        
        for(auto i:root->children)
            postorderUtil(i,v);
        v.push_back(root->val);
    }
    
};