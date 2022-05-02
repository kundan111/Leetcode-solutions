class Solution {
    public int[] sortArrayByParity(int[] nums) {
        
        return approach1(nums);
    }

    public int[] approach1(int[] nums)
    {
        int[] res = new int[nums.length];
        int sz = nums.length;
        int i=0;
        int j=sz-1;

        for (int j2 = 0; j2 < sz; j2++) {
            if((nums[j2] & 1) != 0)
            {
                // odd
                res[j] = nums[j2];
                j--;
            }else{
                // even
                res[i] = nums[j2];
                i++;
            }
        }

        return res;
        
    }
}