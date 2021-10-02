class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
     
        int sz = original.size();
        if(m*n != sz)
        {
            return {};
        }
        
       vector<vector<int>> res(m, vector<int>(n,-1));
        
        int i = 0;
        int k = 0;
        while(k < sz)
        {
          int count = 0;
          
          while(count < n)
          {
              res[i][count] = original[k];
              count++;
              k++;
          }
          i++;
        
        }
        
        
        return res;
        
        
        
        
    }
};