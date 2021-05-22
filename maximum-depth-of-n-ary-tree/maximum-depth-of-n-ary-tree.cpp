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
    int maxDepth(Node* root) {
       if(!root)
          return 0;
        int height = -1;
        
        heightUtil(root,height,1);
        
        return height;
    }
    
    void heightUtil(Node* root, int &height, int temp)
    {
        if(!root)
            return;
        if(height < temp)
            height = temp;
        
        for(auto i:root->children)
        {
            heightUtil(i,height,temp+1);
        }
    }
};