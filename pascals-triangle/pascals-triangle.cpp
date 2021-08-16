class Solution {
public:
    
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res(n);
        res[0] = {1};
        
        if(n == 1)
            return res;
        
        for(int i = 1; i < n; i++)
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
        
        return res;
    }
};