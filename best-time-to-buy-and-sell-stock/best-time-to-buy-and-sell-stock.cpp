class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPriceTillNow = INT_MAX;
        
        for(int price : prices)
        {
            minPriceTillNow = min(price,minPriceTillNow);
            maxProfit = max(maxProfit,price-minPriceTillNow);
        }
        return maxProfit;
    }
};