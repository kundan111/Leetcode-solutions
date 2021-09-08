class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int missing = 0;
        
        for(int val: nums)
        {
            missing ^= val;
        }
        
        
        return missing;
    }
};