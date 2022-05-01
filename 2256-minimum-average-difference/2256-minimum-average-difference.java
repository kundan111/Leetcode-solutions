class Solution {
    public int minimumAverageDifference(int[] nums) {
        
        long[] cumSum = new long[nums.length];

        long prev = 0;
        for (int i = 0; i < cumSum.length; i++) {
            cumSum[i] = prev + nums[i];
            prev += nums[i];
        }

        long minAvg = Long.MAX_VALUE;
        int res = -1;
        for (int i = 0; i < cumSum.length; i++) {
            
            long curMinDiff = findMedianDiff(cumSum, i);
            // System.out.println(i + "->" + curMinDiff);
            if(curMinDiff < minAvg)
            {
                minAvg = curMinDiff;
                res = i;
            }

            
        }
        
        return res;
    }

    long findMedianDiff(long[] cumSum, int i)
    {

        // first half
        int n1 = i+1;
        long sum1 = cumSum[i];

        long avg1 = Math.round(sum1 / n1);

        long avg2 = 0;
        if((cumSum.length - n1) > 0)
        {
           avg2 = (cumSum[cumSum.length-1] - sum1) / (cumSum.length - n1);
        }


        return Math.abs(avg1 -avg2);

    }
}