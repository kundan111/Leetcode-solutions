class Solution {
        public int removeDuplicates(int[] nums) {
        

        if(nums.length <= 1)
        {
            return nums.length;
        }

        // nums has atleast 2 element
        int i = 0;
        int j = 1;

        while (j < nums.length) {
            if(nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
            j++;
        }



        return i+1;
            
    }
}