class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        int row =  m.size();
        int col =  m[0].size();
        
        int res = 0;
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if( i == 0 || j == 0)
                {
                    res += m[i][j];
                }else{
                    if(m[i][j])
                    {
                        int val = min(m[i-1][j],min(m[i][j-1],m[i-1][j-1])) + 1;
                        m[i][j] = val;
                        
                        res += val;
                    }
                }
            }
        }
        
        
        return res;
        
        
    }
    
    
};