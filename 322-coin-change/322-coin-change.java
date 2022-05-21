class Solution {
    int[] coinsGlobal;
    long[] dp;

    public int coinChange(int[] coins, int amount) {

        dp = new long[amount+5];
        coinsGlobal = coins;

        Arrays.fill(dp, -1);

        long temp = recur(amount) ;
        
        return temp == Integer.MAX_VALUE ? -1 : (int)temp;
    }
    

    Long recur(long amount)
    {
        if(amount < 0)
        {
            return (long) Integer.MAX_VALUE;
        }

        if(amount == 0)
        {
            return 0L;
        }

        if(dp[(int)amount] != -1)
        {
            return dp[(int)amount];
        }

        Long coinsMin = (long)Integer.MAX_VALUE;

        for (int i = 0; i < coinsGlobal.length; i++) {
            coinsMin = Math.min(coinsMin, 1 + recur(amount - coinsGlobal[i]));
        }

        
        dp[(int)amount] = coinsMin;
        return coinsMin;

    }
}