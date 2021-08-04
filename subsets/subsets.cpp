class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        recur(nums,vector<int>(),0);
        
        return res;
    }
    
    void recur(vector<int>& nums, vector<int> temp,int indx)
    {
       res.push_back(temp);
       for(int i = indx; i < nums.size(); i++)
       {
           temp.push_back(nums[i]);
           recur(nums,temp,i+1);
           temp.pop_back();
       }
    }
};