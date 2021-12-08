/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    int i = 0;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serString = "";
        preorder(root,serString);
        
        
        
        // cout << serString << endl;
        
        return serString;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        return deserializeUtil(data);
        
        
    }
    
    TreeNode* deserializeUtil(string data) {
     
        vector<string> retVal = spliter(data);
        
        
        return recur(retVal);
        
    }
    
    TreeNode* recur(vector<string> &dataArr)
    {
        
        if(dataArr[i] == "N")
        {
            i++;
            return NULL;
        }
        
        TreeNode* root = new TreeNode(stoi(dataArr[i]));
        i++;
        root-> left = recur(dataArr);
        root-> right = recur(dataArr);
        
        return root;
    }
    
    
    
    vector<string> spliter(string &data)
    {
        int cur = 0;
        int len = data.size();
        vector<string> res;
        while(cur < len-1)
        {
            string temp = "";
            int j = cur;
            while(data[j] != ',')
            {
                temp += data[j];
                j++;
            }
            res.push_back(temp);
            j++;
            cur = j;
        }
        
        return res;
        
    }
    
    void preorder(TreeNode* root, string &serString)
    {
        if(root)
        {
            serString += to_string(root->val) + ",";
            preorder(root->left,serString);
            preorder(root->right,serString);
        }else{
            serString += "N,";
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));