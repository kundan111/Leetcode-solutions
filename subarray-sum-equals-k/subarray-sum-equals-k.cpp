class Solution {
public:
    int subarraySum(vector<int>& nums, int goal) {
        unordered_map<int,int>m;
        int res = 0;
        int cSum = 0;
        m[0] = 1; // for goal as subarray
        for(int val : nums)
        {
            cSum += val;
            res += m[cSum-goal];
            m[cSum]++;
        }
        return res;
        
    }
    
};