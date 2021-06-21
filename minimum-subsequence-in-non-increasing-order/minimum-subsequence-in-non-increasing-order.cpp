class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        
         int initial_sum  = 0; 
         initial_sum = accumulate(nums.begin(), nums.end(), initial_sum);
        
        vector<int> res;
        int tempSum = 0;
        int i = 0;
        while(tempSum <= initial_sum - tempSum)
        {
            tempSum = tempSum + nums[i];
            res.push_back(nums[i]);
            i++;
        }
        return res;
    }
};