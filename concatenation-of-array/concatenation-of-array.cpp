class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int sz = nums.size();
        vector<int> res(2*sz);
        
        for(int i = 0; i < sz; i++)
        {
            res[i] = nums[i];
        }
        
        for(int i = sz, j = 0; i < 2*sz && j<sz; i++,j++)
        {
            res[i] = nums[j];
        }
        
        return res;
    } 
};