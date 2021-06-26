class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int sz = nums.size();
        
        for(int i = sz - 1; i >= 2; i--)
        {
            if(nums[i] < nums[i-1] + nums[i-2])
                return nums[i] + nums[i-1] + nums[i-2];
        }
        
        return 0;
    
    }
    
    
};