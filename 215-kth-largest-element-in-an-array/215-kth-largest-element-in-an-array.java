class Solution {
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        int sz = nums.length;

        
        // System.out.println(Arrays.toString(nums));


        return nums[sz- k];
    }
}