class Solution {
public:
    bool canPartition(vector<int>& nums) {
     
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        if(sum & 1)
            return 0;
        
        int k = sum/2;
        
        
        int N = nums.size();
            
        vector<vector<int>> dp( k+1 , vector<int> (N+1,-1));
        
        
        return helper(N,nums,k,0,dp);
    }
    
    
    bool helper(int N, vector<int>& arr, int k, int i, vector<vector<int>> &dp)
    {
        if(k < 0)
        {
            return false;
        }
        if(k == 0)
        {
            return true;
        }
        
        if(i >= N)
        {
            return false;
        }
        
        bool b1,b2;
        
        if(k-arr[i] >= 0 )
        {
            if(dp[k-arr[i]][i+1] != -1)
            {
                b1 = dp[k-arr[i]][i+1];
            }else{
                b1 = helper(N,arr,k-arr[i],i+1,dp);
                dp[k-arr[i]][i+1] = b1;
            }
            
        }else{
            b1 = 0;
        }
        
        if(dp[k][i+1] != -1)
        {
            b2 = dp[k][i+1];
        }else{
            b2 = helper(N,arr,k,i+1,dp);
            dp[k][i+1] = b2;
        }
        
        // return helper(N,arr,k-arr[i],i+1) || helper(N,arr,k,i+1);
        return b1 || b2;
    }
};