class Solution {
    public int[] sortArrayByParity(int[] nums) {
        
        return approach2(nums);
    }

    public int[] approach2(int[] nums)
    {
        int sz = nums.length;
        int i=0;
        int j=sz-1;


        while (i < j) {
            if((nums[i] & 1) != 0)
            {
                // odd
                // swap with j
                swap(nums, i, j);
                j--;
            }else{
                // even 
                i++;
            }
        }
        
        return nums;
    }
    

    void swap(int[] arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}