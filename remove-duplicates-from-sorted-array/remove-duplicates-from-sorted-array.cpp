class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        
        int sz = nums.size();
        int i = 0;
        int j = 1;
        
        while(j < sz)
        {
            if(nums[i] != nums[j])
            {
                i = i+1;
                nums[i] = nums[j];
            }
            j++;
        }
        
        return i+1;
    }
};