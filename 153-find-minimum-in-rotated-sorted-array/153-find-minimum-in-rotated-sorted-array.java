class Solution {
    public int findMin(int[] nums) {
        
        
        return nums[getPivotPoint(nums)];
        
    }
    
    
    int getPivotPoint(int[] nums)
    {

        int sz = nums.length;

        int l = 0;
        int r = sz - 1;

        while (l <= r) {
            int mid =  l + (r-l)/2;
            int left = -1;
            int right = -1;
            if(mid == 0)
            {
                left = Integer.MAX_VALUE;
            }else{
                left = nums[mid-1];
            }

            if(mid == sz-1)
            {
                right = Integer.MAX_VALUE;
            }else{
                right = nums[mid+1];
            }


            if(left > nums[mid] && nums[mid] < right)
            {
                return mid;
            }else{
                if(nums[r] > nums[mid])
                {
                    // right side sorted
                    r = mid-1;
                }else{
                    // left side sorted
                    l = mid+1;
                }
            }
                
            
        }


        //nums is sorted
        // System.out.println("nums is sorted...");

        return 0;
    }
}