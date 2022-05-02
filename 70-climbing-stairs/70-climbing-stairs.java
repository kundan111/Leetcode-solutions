class Solution {
    public int climbStairs(int n) {
        
//         int[] dp = new int[n+2];
//         dp[0] = 0;
//         dp[1] = 1;
//         dp[2] = 2;

//         for (int i = 3; i < dp.length; i++) {
//             dp[i] = dp[i-1] + dp[i-2];
//         }

//         // System.out.println(Arrays.toString(dp));

//         return dp[n];
        
        return approach2(n);
        
    }
    
    public int approach2(int n) 
    {
        if(n == 1)
        {
            return 1;
        }

        if(n == 2)
        {
            return 2;
        }


        int first = 1;
        int second = 2;

        int i = 0;
        

        while (i != n-3) {
            int temp = first;
            first = second;
            second = temp + second;
            i++;
        }
        return first + second;
    }
}