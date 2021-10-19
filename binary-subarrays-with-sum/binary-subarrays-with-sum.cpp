class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>m;
        int res = 0;
        int cSum = 0;
        m[0] = 1; // for reference
        for(int val : nums)
        {
            cSum += val;
            if(m[cSum-goal])
            {
                res += m[cSum-goal];
            }
            m[cSum]++;
        }
        return res;
    }
};