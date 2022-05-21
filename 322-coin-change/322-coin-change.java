class Solution {
    HashMap<Long,Long> dp = new HashMap<>();

    public int coinChange(int[] coins, int amount) {
        long temp = recur(coins, amount) ;
        // System.out.println("temp: " + temp);
        return temp == Integer.MAX_VALUE ? -1 : (int)temp;
    }


    Long recur(int[] coins, long amount)
    {
        // System.out.println("recur(coins," +  amount + ")");
        if(amount < 0)
        {
            return (long) Integer.MAX_VALUE;
        }

        if(amount == 0)
        {
            return 0L;
        }

        if(dp.containsKey(amount))
        {
            return dp.get(amount);
        }

        Long coinsMin = (long)Integer.MAX_VALUE;

        for (int i = 0; i < coins.length; i++) {
            coinsMin = Math.min(coinsMin, 1 + recur(coins, amount - coins[i]));
        }
        
        
        // System.out.println("coinsMin: " + coinsMin);
        // System.out.println("------------------");
        dp.put(amount, coinsMin);
        return coinsMin;

    }
}