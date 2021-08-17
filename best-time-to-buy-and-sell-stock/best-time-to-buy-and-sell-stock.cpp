class Solution {
public:
    int maxProfit(vector<int>& p) {
        int sz = p.size();
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for(int i = 0; i < sz;i++)
        {
            minPrice = min(minPrice,p[i]);
            maxProfit = max(maxProfit,p[i]-minPrice);
        }
        
        
        return maxProfit;
        
        
    }
};