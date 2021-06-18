/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<Node*>v;
    Node* connect(Node* root) {
        helper(root,0);
        return root;
    }
    
    void helper(Node* root,int d)
    {
        if(!root)
            return;
        if(d == v.size())
        {
            v.push_back(root);
        }else{
            Node* cur = v[d];
            cur->next = root;
            v[d] = root;
        }
        
        helper(root->left,d+1);
        helper(root->right,d+1);
    }
    
    
};