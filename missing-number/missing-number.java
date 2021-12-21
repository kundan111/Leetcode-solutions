class Solution {
    public int missingNumber(int[] nums) {
        
        int len = nums.length;
        int[] temp = new int[len+1];
        
        for(int val : nums)
        {
            temp[val] = 1;
        }
        
        for(int i = 0; i < len+1; i++)
        {
            if(temp[i] == 0)
            {
                return i;
            }
        }
        
        
        return -1;
    }
}