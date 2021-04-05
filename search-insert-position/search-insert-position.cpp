class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       // M1
       int sz = nums.size();
       for(int i = 0; i < sz; i++)
       {
           if(nums[i] == target)
                return i;
            if(nums[i] > target)
                return i;
       }
       return sz;     
    }
};