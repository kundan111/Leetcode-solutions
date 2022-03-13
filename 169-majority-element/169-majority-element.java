class Solution {
    public int majorityElement(int[] nums) {
        
        int ans = nums[0];
        int curCount = 1;
        for (int i = 1; i < nums.length; i++) {
            if(ans == nums[i])
            {
                curCount++;
            }else{
                curCount--;
                if(curCount == 0)
                {
                    curCount = 1;
                    ans = nums[i];
                }
            }
        }
        
        return ans;
        
    }
}