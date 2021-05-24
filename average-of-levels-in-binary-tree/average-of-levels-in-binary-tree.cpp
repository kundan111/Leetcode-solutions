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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<double>> res;
        if(!root)
            return vector<double>();
        
        levelOrderUtil(root,res,0);
        
        return calAvg(res);
    }
    
    
    void levelOrderUtil(TreeNode* root, vector<vector<double>> &res, int level)
    {
        if(!root)
            return;
        if(res.size() == level)
            res.push_back(vector<double>());
        
        
        
        res[level].push_back(root->val);
        levelOrderUtil(root->left,res,level+1);
        
        levelOrderUtil(root->right,res,level+1);
        
    }
    
    vector<double> calAvg(vector<vector<double>> &v)
    {
        vector<double> res;
        int sz = v.size();
        for(int i = 0; i < sz; i++)
        {
            vector<double> temp = v[i];
            int ssz = temp.size();
            int j = 0;
            long long int sum = 0;
            while(j < ssz)
            {
                sum += temp[j];
                j++;
            }
            
            double avg = (double)sum/ssz;
            res.push_back(avg);
            
        }
        
        return res;
    }
};