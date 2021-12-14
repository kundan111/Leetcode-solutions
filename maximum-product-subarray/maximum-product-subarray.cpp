class Solution {
public:
    int maxProduct(vector<int>& nums) {
       
        
        int curMax = 1;
        int curMin = 1;
        
        int res = *max_element(nums.begin(),nums.end());
        
        for(int val : nums)
        {
            int temp = curMax * val;
            curMax = max(curMax * val, max(curMin*val, val));
            curMin = min(temp, min(curMin*val, val));
            
            res = max(res,curMax);
        }
        
        return res;    
    }
};