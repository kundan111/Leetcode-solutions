class Solution {
    public int[] searchRange(int[] nums, int target) {
     
        int[] ret = new int[2];
        ret[0] = -1;
        ret[1] = -1;
        int sz = nums.length;

        for (int i = 0; i < sz; i++) {
            if(nums[i] == target)
            {
                ret[0] = i;
                break;
            }
        }

        for (int i = sz-1; i >= 0; i--) {
            if(nums[i] == target)
            {
                ret[1] = i;
                break;
            }
        }
     
     
        return ret;
        
    }
}