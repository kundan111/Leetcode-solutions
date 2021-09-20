class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1)
        {
            return;
        }
        
        int i = 0;
        while(i < sz && nums[i] != 0)
        {
            i++;
        }
        
        int j = i+1;
        
        while(j < sz)
        {
            if(nums[j] != 0)
            {
                swap(nums[j],nums[i]);
                i++;
            }
            j++;
        }
        
        
        
    }
};