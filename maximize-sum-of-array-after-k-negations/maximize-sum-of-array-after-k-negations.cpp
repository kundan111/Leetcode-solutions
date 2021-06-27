class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < nums.size() && k >0 && nums[i] < 0; i++,k--)
        {
            nums[i] = -nums[i];
        }
        
        int sum = 0;
        int minEle = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            minEle = min(nums[i],minEle);
        }
        
        return sum - (k%2) * 2 * minEle;
        
        
        
    }
};