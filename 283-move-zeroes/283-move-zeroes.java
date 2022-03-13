class Solution {
    public void moveZeroes(int[] nums) {
        int sz = nums.length;
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
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                i++;
            }
            j++;
        }
    }
}