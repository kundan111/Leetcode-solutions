class Solution {
    public int maxProfit(int[] prices) {
        
        int res = 0;
        int minTillNow = Integer.MAX_VALUE;

        for (int price : prices) {
            minTillNow = Math.min(minTillNow, price);
            res = Math.max(res, price-minTillNow);
        }
        
        return res;
    }
}