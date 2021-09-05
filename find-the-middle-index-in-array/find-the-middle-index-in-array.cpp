class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int leftSum = 0;
        
        int sz = nums.size();
            
        for(int i =0 ; i < sz; i++)
        {
            totalSum -= nums[i];
            if(leftSum == totalSum)
            {
                return i;
            }
            leftSum += nums[i];
            
        }
        
        return -1;
    }
};