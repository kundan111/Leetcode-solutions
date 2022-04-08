class Solution {
    public int search(int[] nums, int target) {

        if(nums.length < 3)
        {
            for (int i = 0; i < nums.length; i++) {
                if(nums[i] == target)
                {
                    return i;
                }
            }
            return -1;
        }

        int pivotPoint = getPivotPoint(nums);
        
        
        // System.out.println("pivotPoint: " + pivotPoint);
            

        if(pivotPoint == 0)
        {
            return binarySearch(nums, 0, nums.length-1, target);
        }

        int res1 = binarySearch(nums, 0, pivotPoint-1, target);
        
        
        if(res1 != -1)
        {
            return res1;
        }
        int res2 = binarySearch(nums, pivotPoint, nums.length-1, target);

        if(res2 != -1)
        {
            return res2;
        }

        return -1;



    }

    int binarySearch(int[] nums, int l , int r, int target)
    {
        while (l <= r) {
            
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
            {
                return mid;
            }

            if(nums[mid] > target)
            {
                r = mid-1;
            }else{
                l = mid+1;
            }

        }
        return -1;
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
        System.out.println("nums is sorted...");

        return 0;
    }
}