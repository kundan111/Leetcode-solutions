class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int i = 0;
        int sz = flowerbed.size();
        while(i < sz)
        {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) &&  (i == sz-1 || flowerbed[i+1] == 0))
            {
                flowerbed[i] = 1;
                count++;
            }
            i++;
        }
        
        return count >= n;
        
    }
};