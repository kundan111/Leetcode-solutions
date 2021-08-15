class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        
        int sz = nums.size();
        
        for(int i = 1; i < sz-1; i++)
        {
                if(2*nums[i] == nums[i-1]+nums[i+1])
                {
                    swap(nums[i],nums[i+1]);
                }
        }
        
         for(int i = sz-2; i >= 1 ; i--)
        {
                if(2*nums[i] == nums[i-1]+nums[i+1])
                {
                    swap(nums[i],nums[i-1]);
                }
        }
        
        
        return nums;
    }
};