class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int sz = prices.size();
        for(int i = 0; i < sz; i++)
        {
            int cur = prices[i];
            for(int j = i+1; j < sz; j++)
            {
                if(prices[j] <= cur)
                {
                    prices[i] -= prices[j];
                    break;
                }
            }
        }
        
        return prices;
    }
};