class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int sz = nums.size();
        
        
        int res = 0;
        int mn = INT_MAX;
        for(int i = 0; i < sz; i++)
        {
            mn = min(mn,nums[i]);
            res = max(res,nums[i]-mn);
        }
        
        return res != 0 ? res : -1;
    }
};