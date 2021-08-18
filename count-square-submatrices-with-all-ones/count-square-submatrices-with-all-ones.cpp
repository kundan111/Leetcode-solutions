class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        int row =  m.size();
        int col =  m[0].size();
        
        int maxSqSize = min(row,col);
        vector<int> res(maxSqSize+1,0);
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(m[i][j])
                {
                    for(int sz = 1 ; sz <= maxSqSize; sz++)
                    {
                        if(isSquare(m,i,j,row,col,sz))
                        {
                            res[sz]++;    
                        }
                        
                        
                    }
                }
            }
        }
        
        return accumulate(res.begin(),res.end(),0);
    }
    
    bool isSquare(vector<vector<int>>& m,int i, int j, int row, int col, int sz)
    {
        if(( i < 0 || i >= row) || (j < 0 || j >= col))
            return false;
        bool checkBound = ((i + sz-1 < row) && (j + sz-1 < col));
        
        if(!checkBound)
            return false;
        
        for(int s = i; s <= i + sz-1 ; s++)
        {
            for(int e = j ; e <= j + sz -1; e++)
            {
                if(m[s][e] != 1)
                    return false;
            }
            
        }
        return true;
    }
};