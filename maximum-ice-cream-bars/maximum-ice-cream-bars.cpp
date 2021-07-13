class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin(),costs.end());
        
        int i = 0;
        int sz = costs.size();
        
        int res = 0;
        while(i < sz && coins)
        {
            if(costs[i] <= coins)
            {
                res++;
                coins -= costs[i];
            }
            i++;
        }
        
        return res;
        
    }
};