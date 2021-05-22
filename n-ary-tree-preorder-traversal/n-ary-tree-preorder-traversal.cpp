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
    vector<int> preorder(Node* root) {
        
        vector<int> res;
        if(!root)
            return res;
        
        preorderUtil(root, res);
        
        return res;
        
    }
    
    void preorderUtil(Node* root, vector<int> &v)
    {
        stack<Node*> tempStack;
        
        
        tempStack.push(root);
        
        
        while(!tempStack.empty())
        {
            Node* top  = tempStack.top();
            v.push_back(top->val);
            vector<Node*> tempVec = top->children;
            tempStack.pop();
            
            int sz = tempVec.size();
            
            int counter = sz-1;
            
            while(counter >= 0)
            {
                tempStack.push(tempVec[counter]);
                counter--;
            }
            
            
        }
        
    }
    
};