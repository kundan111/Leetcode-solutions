class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int sz = nums.size();
        vector<int> res(sz);
        for(int i = 0; i < sz; i++)
        {
            res[i] = nums[nums[i]];
        }
        
        return res;
    }
};