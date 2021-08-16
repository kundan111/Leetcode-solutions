class Solution {
public:
    vector<int> getRow(int n) {
       vector<vector<int>> res(n+1);
        res[0] = {1};
        
        if(n == 0)
            return {1};
        
        
        
        for(int i = 1; i <= n; i++)
        {
            res[i].push_back(1);
            int sz = res[i-1].size();
            for(int j = 0; j < sz; j++)
            {
               if(j < sz && j+1 < sz)
               {
                   res[i].push_back(res[i-1][j] + res[i-1][j+1]);
               }
            }
            res[i].push_back(1);
            
        }
        
        return res[n]; 
    }
};