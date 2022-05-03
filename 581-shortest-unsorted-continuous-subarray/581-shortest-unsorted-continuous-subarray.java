class Solution {
    public int findUnsortedSubarray(int[] nums) {
        
        int[] original = Arrays.copyOf(nums, nums.length);
        Arrays.sort(nums);

        int sz = nums.length;

        int i = 0;
        int start = -1;
        int end = -1;
        while (i < sz) {

            if(original[i] != nums[i])
            {
                start = i;
                break;
            }
            i++;
        }

        i = sz-1;

        while (i >= 0) {
            if(original[i] != nums[i])
            {
                end = i;
                break;
            }
            i--;
        }

        if(start == -1 || end == -1)
        {
            return 0;
        }

        return end -start +1 ;

        
    }
}