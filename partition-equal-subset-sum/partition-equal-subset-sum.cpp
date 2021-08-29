class Solution {
public:
    bool canPartition(vector<int>& nums) {
     
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        if(sum & 1)
            return 0;
        
        int k = sum/2;
        
        
        int N = nums.size();
            
        vector<vector<int>> dp( N+1 , vector<int> (k+1,-1));
        
        for(int i = 0; i < N+1; i++)
        {
            for(int j = 0; j < k+1; j++)
            {
                if(i == 0) // there is no number 
                {
                    dp[i][j] = 0;
                }
                
                if(j == 0) // sum is 0
                {
                    dp[i][j] = 1;
                }
            }
        }
        
        
        
        for(int i = 1; i < N+1; i++)
        {
            for(int j = 1; j < k+1; j++)
            {
                if(nums[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        
        return dp[N][k];
        
        
    }
    
    
    
};