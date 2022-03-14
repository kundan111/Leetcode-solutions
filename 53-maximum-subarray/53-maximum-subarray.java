class Solution {
    public int maxSubArray(int[] nums) {
        
        
        int res = Integer.MIN_VALUE;
        int runningSum = 0;


        for (int val : nums) {
            
            runningSum += val;
            res = Math.max(runningSum, res);

            if(runningSum < 0)
            {
                runningSum = 0;
            }

        }


     
        return res;
    }
}