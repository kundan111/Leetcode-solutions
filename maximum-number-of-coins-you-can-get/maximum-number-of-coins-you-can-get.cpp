class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        sort(piles.begin(),piles.end());
        int orisz = piles.size();
        int sz = orisz;
        int res = 0;
        for(int i = 0; i < orisz/3; i++)
        {
            res = res + piles[sz-2];
            sz = sz -2;
        }
        
        return res;
        
    }
};