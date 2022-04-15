class Solution {
    public void rotate(int[] nums, int k) {
        
        int[] newArr = new int[nums.length];

        int sz = nums.length;

        for (int i = 0; i < sz; i++) {
            newArr[(i+k)%sz] = nums[i];
        }

        for (int i = 0; i < newArr.length; i++) {
            nums[i] = newArr[i];
        }
    }
    
}