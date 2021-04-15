class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res = 1;
        int i = 0;
        int sz = nums.size();
        int sign = INT_MAX;
        while( i != sz)
        {
            int ele = nums[i];
            if(ele == 0)
            {
                res = 0;
                break;
            }
            
           sign = ele > 0 ? 1 : -1;  
           res = res * sign;
            i++;
        }
        
        if(res == 0)
            return 0;
        return res > 0 ? 1 : -1;  
        
        
    }
};