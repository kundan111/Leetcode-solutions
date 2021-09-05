class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sz = nums.size();
        vector<int> Sum(sz);
        
        int tempLeft = 0;
        int tempRight = 0;
        for(int i = 0; i < sz; i++)
        {
            Sum[i] = tempLeft + nums[i];
            tempLeft = tempLeft + nums[i];
        }
        tempLeft = 0;
        int ans = INT_MAX;
        for(int i = sz - 1; i >= 0; i--)
        {
            Sum[i] -= nums[i]+tempLeft;
            if(Sum[i] == 0)
            {
                ans = min(ans,i);
            }
            tempLeft += nums[i];
        }
        
        
        return ans == INT_MAX ? -1 : ans;
    }
};