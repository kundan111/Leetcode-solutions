class Solution {
public:
    int row;
    int col;
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        row = mat.size();
        col = mat[0].size();
        for(int i = 0; i <row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                int cur = mat[i][j];
                
                int upCell = isValid(i-1,j) ? mat[i-1][j] :  -1;
                int rightCell = isValid(i,j+1) ? mat[i][j+1] : -1;
                int downCell = isValid(i+1,j) ? mat[i+1][j] : -1;
                int leftCell = isValid(i,j-1) ? mat[i][j-1] : -1;
                
                if(cur > upCell && cur > rightCell && cur > downCell && cur > leftCell)
                {
                    return {i,j};
                }
                    
            }
        }
        
        return {-1,-1};
        
    }
    
    bool isValid(int i, int j)
      {
        
            return ((i >=0  && i < row)  && (j >= 0 &&  j < col));
     }
};