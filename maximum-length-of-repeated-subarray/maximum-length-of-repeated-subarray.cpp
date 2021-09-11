class Solution {
    private:
        vector<int> nums1Cop;
        vector<int> nums2Cop;
        int m;
        int n;
        vector<vector<int>> dp;
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        nums1Cop =  move(nums1);
        nums2Cop =  move(nums2);
        
        m = nums1Cop.size();
        n = nums2Cop.size();
        
        dp.resize(m+1,vector<int>(n+1,-1));
        
        
        for(int i = 0; i < n+1; i++)
        {
            dp[0][i] = 0;
        }
        
        for(int i = 0; i < m+1; i++)
        {
            dp[i][0] = 0;
        }
        
        int maxRes = -1;
        
        for(int i = 1; i < m+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                // cout << "i: " << i << " j: " << j << endl;
                if(nums1Cop[i-1] == nums2Cop[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    
                }else{
                    dp[i][j] = 0;
                }
                maxRes = max(maxRes,dp[i][j]);
            }
        }
        
        
        
        
        
        return maxRes;
    }
    
    
};