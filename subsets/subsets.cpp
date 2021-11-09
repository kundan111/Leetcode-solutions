class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        recur(nums,vector<int>(),0,res);
        return res;
    }
    
    void recur(vector<int>& nums, vector<int> temp,int indx,vector<vector<int>> &res)
    {
       res.push_back(temp);
       for(int i = indx; i < nums.size(); i++)
       {
           temp.push_back(nums[i]);
           
           recur(nums,temp,i+1,res);
           temp.pop_back();
       }
    }
    
    void print(vector<int> &temp)
    {
        int sz = temp.size();
        for(int i = 0; i < sz; i++)
        {
            cout << temp[i] << endl;
        }
        cout << endl;
    }
};