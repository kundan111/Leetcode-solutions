class Solution {
public:
    int findMin(vector<int>& nums) {
        int sz = nums.size();
        for(int i = 0; i < sz ; i++)
        {
            if(!isNormal(nums,i,sz))
            {
                return min(i-1 >= 0 ? nums[i-1] : INT_MAX,min(nums[i],i+1 < sz ? nums[i+1] : INT_MAX));
            }
        }
        
        return nums[0];
    }
    
    bool isNormal(vector<int>& nums, int i, int sz)
    {
        int leftVal = (i-1) >=0  ? nums[i-1] : INT_MIN;
        int rightVal = (i + 1) < sz ? nums[i+1] : INT_MAX;
        
        return  leftVal< nums[i] && nums[i] < rightVal;
    }
};