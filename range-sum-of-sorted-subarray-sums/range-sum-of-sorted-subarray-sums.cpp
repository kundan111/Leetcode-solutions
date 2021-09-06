class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int sz = nums.size();
        vector<int>sumArray;
        
        int mod = 1000000007;
        
        
        for(int i = 0; i < sz; i++)
        {
            int sum = nums[i];
            sumArray.push_back(sum);
            for(int j = i+1; j < sz; j++)
            {
                sum += nums[j];
                sumArray.push_back(sum);
            }
            
        }
        
        sort(sumArray.begin(),sumArray.end());
        
        int res = 0;
        for(int i = left-1; i <= right-1; i++)
        {
            res = (res + sumArray[i])%mod;
        }
        
        return res%mod;
    
    }
};