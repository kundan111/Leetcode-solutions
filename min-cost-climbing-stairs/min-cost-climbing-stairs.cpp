class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int dp[n];
        memset(dp,-1,sizeof dp);
        
        // for(int v: dp)
        // {
        //     cout << v << " ";
        
        // }
            
        
        return min(helper(0,cost,dp),helper(1,cost,dp));
    }
    
    int helper(int cur,vector<int>& cost, int dp[])
    {
        if(cur == cost.size()-1 )
            return cost[cost.size()-1];
        if(cur >= cost.size())
            return 0;
        
        if(dp[cur] != -1)
            return dp[cur];
        
        int op1 = helper(cur+1,cost,dp);
        int op2 = helper(cur+2,cost,dp);
        
        
        return dp[cur] = cost[cur] + min(op1,op2);
        
    }
};