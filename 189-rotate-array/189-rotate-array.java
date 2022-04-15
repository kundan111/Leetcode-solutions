class Solution {
    public void rotate(int[] nums, int k) {
        
        k = k%nums.length;
        approach2(nums,k);
    }
    
    public void approach2(int[] nums, int k) {
            int sz = nums.length;
            reverse(nums, 0, sz-1);
            reverse(nums, 0, k-1);
            reverse(nums, k, sz-1);
    }
    
    void reverse(int[] nums, int i, int j)
    {
        
        while (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
}