class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // Brute force
        int res = 0;
        for(auto v: grid)
        {
            for(auto val: v)
            {
                if(val < 0)
                {
                    res++;
                }
            }
        }
        
        
        
        return res;
    }
};