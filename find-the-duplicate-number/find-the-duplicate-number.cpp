class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sz = nums.size();
        int i = 0;
        while(i < sz-1)
        {
            if(nums[i] == nums[i+1])
            {
                return nums[i];
            }
            i++;
        }
        
        
        return -1;
    }
};