class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int row = m.size();
        int col = m[0].size();
        
        
        vector<int>row_zero(row,1);
        vector<int>col_zero(col,1);
        
        for(int i = 0; i < row;i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(m[i][j] == 0)
                {
                    row_zero[i] = 0;
                    col_zero[j] = 0;
                }
            }
        }
        
       for(int i = 0; i < row;i++)
        {
           
            for(int j = 0; j < col; j++)
            {
                if(row_zero[i] == 0 || col_zero[j] == 0)
                {
                    m[i][j] =0;
                    
                }
            }
        }
        
    }
};