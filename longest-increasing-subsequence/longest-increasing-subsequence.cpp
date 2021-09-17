class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        vector<int> dp(sz,0);
        
        int res = 0;
        for(int i = 0; i < sz; i++)
        {
            int locMax = 0;
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                {
                    if(dp[j] > locMax)
                    {
                        locMax = dp[j]; 
                    }
                    
                }
            }
            
            dp[i] = locMax + 1;
            if(dp[i] > res)
            {
                res = dp[i];
            }
        }
        
        return res;
    }
};