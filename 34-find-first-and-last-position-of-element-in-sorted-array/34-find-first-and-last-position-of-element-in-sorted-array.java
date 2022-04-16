class Solution {
    public int[] searchRange(int[] nums, int target) {
        
        return approach2(nums, target);
    }
    
    
    public int[] approach2(int[] nums, int target) {
        
        int[] ret = new int[2];
        ret[0] = -1;
        ret[1] = -1;



        int end = binarySearch(nums, target, true);
        int first = binarySearch(nums, target, false);


        ret[1] = end;
        ret[0] = first;

        return ret;
    
    }
    
    int binarySearch(int[] nums, int target, boolean dir)
    {

        int res = -1;

        int l = 0;
        int r = nums.length - 1;
        while (l <= r) {

            int mid = l + (r-l)/2;
            if(nums[mid] == target)
            {
                res = mid;
                if(dir)
                {
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }else if(nums[mid] < target)
            {
                l = mid+1;
            }else{
                r = mid-1;
            }

        }



        return res;
        
    }
}