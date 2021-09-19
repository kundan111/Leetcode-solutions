class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int sz = nums.size();
        vector<bool> left(sz);
        // vector<bool> right(sz);
        
        int mx = nums[0];
        for(int i = 1; i < sz ; i++)
        {
            if(nums[i] > mx)
            {
                left[i] = true;
                mx = nums[i];
            }else{
                left[i] = false;
            }
        }
        
        /*
        
        for(int i = sz-2; i >= 0 ; i--)
        {
            if(nums[i] < mn)
            {
                right[i] = true;
                mn = nums[i];
            }else{
                right[i] = false;
            }
        }
        
        */
        
        int mn = nums[sz-1];
        
        int res = 0;
        for(int i = sz-2; i > 0 ; i--)
        {
            int cur = nums[i];
            if(left[i] && nums[i] < mn)
            {
                res += 2;
            }else if(nums[i-1] < cur && cur < nums[i+1])
            {
                res += 1;
            }else{
                res += 0;
            }
            mn = min(mn,cur);
            
        }
        
        return res;
        
        
        
        
        
        
        
        return 0;
    }
};