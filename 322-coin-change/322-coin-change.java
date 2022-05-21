class Solution {
    long[] dp;

    public int coinChange(int[] coins, int amount) {

        dp = new long[amount+5];

        Arrays.fill(dp, -1);

        long temp = recur(coins, amount) ;
        return temp == Integer.MAX_VALUE ? -1 : (int)temp;
    }


    Long recur(int[] coins, long amount)
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

        for (int i = 0; i < coins.length; i++) {
            coinsMin = Math.min(coinsMin, 1 + recur(coins, amount - coins[i]));
        }

        
        dp[(int)amount] = coinsMin;
        return coinsMin;

    }
}