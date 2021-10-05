class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int sz = nums.size();
        double prevWinSum = accumulate(nums.begin(),nums.begin()+k,0);
        int i = 0;
        int j = k;
        
        long long int res = (double)prevWinSum;
        while(j < sz)
        {
            int newWinSum = prevWinSum - nums[i] + nums[j];
            
            if(newWinSum >= res)
            {
                res = newWinSum;
            }
            
            prevWinSum = newWinSum;
            i++;
            j++;
            
        }
        
        
        // cout << "res: " << res << endl;
        
        return (double)((double)res/(double)k);
        
    }
};