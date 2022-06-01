class Solution {
    public int[] runningSum(int[] nums) {
        int i = 1;
        int sz = nums.length;
        while(i < sz)
        {
            nums[i] += nums[i-1];
            i++;
        }
        
        return nums;
    }
    
}