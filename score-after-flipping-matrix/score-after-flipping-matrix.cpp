class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        
        vector<int> temp(cols,0);
        
        for(int i = 0; i < rows; i++)
        {
            
            if(grid[i][0] == 0)
            {
                flipRow(grid,i,rows,cols);
            }
            
            // this row is first element is converted to one for sure
            
            for(int j = 1; j < cols; j++)
            {
                  if(grid[i][j])
                  {
                      temp[j]++;
                  }
            }
        }
        
        for(int i = 1; i < cols; i++)
        {
            // if number of 1s is less than number of 0s
            if(temp[i] < rows - temp[i])
            {
                //flip that col
                flipCol(grid,i,rows,cols);
            }
        }
        
        // calculate the sum and return it
        
        int res = 0;
        for(auto v: grid)
        {
            int tempSum = 0;
            for(int i = v.size()-1; i >= 0 ; i--)
            {
                if(v[i])
                {
                    int multiplier = v.size() - i - 1;
                    tempSum = tempSum + pow(2,multiplier);
                }
            }
            
            res = res + tempSum;
        }
        
        return res;
    }
    
    void flipRow(vector<vector<int>>& grid, int rowNumber, int rows, int cols)
    {
        for(int i = 0; i < cols; i++)
        {
            if(grid[rowNumber][i])
            {
                grid[rowNumber][i] = 0;
            }else{
                grid[rowNumber][i] = 1;
            }
        }
        
    }
    
    void flipCol(vector<vector<int>>& grid, int colNumber, int rows, int cols)
    {
        for(int i = 0; i < rows; i++)
        {
            if(grid[i][colNumber])
            {
                grid[i][colNumber] = 0;
            }else{
                grid[i][colNumber] = 1;
            }
        }
        
    }
    
    
};