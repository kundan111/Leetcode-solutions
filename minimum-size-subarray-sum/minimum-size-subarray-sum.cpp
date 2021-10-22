class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sz = nums.size();
        int l = 0;
        int res = INT_MAX;
        
        int running_sum = 0;
        
        for(int r = 0; r < sz; r++)
        {
            running_sum += nums[r];
            while(running_sum >= target)
            {
                res = min(res,r-l+1);
                running_sum -= nums[l];
                l++;
            }
        }
    return res != INT_MAX ? res : 0; 
    }
    
   
 
};