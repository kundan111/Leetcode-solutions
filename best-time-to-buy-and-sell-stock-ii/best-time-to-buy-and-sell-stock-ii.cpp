// IT WORKS I DONT KNOW WHY
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int sz = prices.size();
        int i = 0;
        int profit = 0;
        
        while( i < sz-1)
        {
            int cur = prices[i];
            int nextCur = prices[i+1];
            
            if(nextCur > cur)
            {
                profit += (nextCur-cur);
            }
            i++;
        }
        
        return profit;
    }
};