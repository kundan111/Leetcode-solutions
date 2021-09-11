class Solution {
private:
    int row;
    int col;
    int maxSqSizePossible;
    vector<vector<int>> matCop;
    vector<vector<int>> cumuMat;
public:
    
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        row = mat.size();
        col = mat[0].size();
        maxSqSizePossible = min(row,col);
        matCop = move(mat);
        
        cumuMat.resize(row, vector<int>(col,0));
        
        buildCumMat();
        
        int maxRet = -1;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                int l = 1;
                int r = maxSqSizePossible;
                int ret = -1;
                while(l <= r)
                {
                    int side = l + (r-l)/2;
                    if(isSquarePossible(i,j,side))
                    {
                        int sum = calculateSum(i,j,side);
                        // cout << "i: " << i << " j: " << j << " side: " << side << endl;
                        // cout << "sum: " << sum << endl;
                        if(sum <= threshold)
                        {
                            ret = side;
                            l = side + 1;
                        }else{
                            r = side-1;
                        }
                    }
                    else{
                       r = side -1;
                    }
                }
                // cout << "ret: " << ret << endl;
                
                maxRet = max(ret,maxRet);
                if(maxRet == maxSqSizePossible)
                {
                    
                    return maxRet;
                }
                
            }
        }
        
        return maxRet != -1 ? maxRet : 0;
        
        
    }
    
    bool isSquarePossible(int i, int j, int side)
    {
        int lastCol = j + side - 1;
        int lastRow = i + side - 1;
        
        return (lastRow < row && lastCol < col);
    }
    
    bool isValid(int i, int j)
    {
        return ((i >= 0 && i < row) && (j>=0 && j < col));
    }
    
    
    int calculateSum(int p, int q, int side)
    {
        
        int diagonalX = p + side -1;
        int diagonalY = q + side -1;
        
        int biggest1 = cumuMat[diagonalX][diagonalY];
        int biggest2 = isValid(p-1,diagonalY) ? cumuMat[p-1][diagonalY] : 0;
        int biggest3 = isValid(diagonalX,q-1) ? cumuMat[diagonalX][q-1] : 0;
        int biggest4 = isValid(p-1,q-1) ? cumuMat[p-1][q-1] : 0;
        return biggest1 - biggest2 - biggest3 + biggest4;
        
        
        /*
        int lastX = p + side - 1;
        int lastY = q + side - 1;
        
        int ret = 0;
        for(int i = p ; i <= lastX ; i++)
        {
            for(int j = q; j <= lastY; j++)
            {
                ret += matCop[i][j];
            }
        }
        
        return ret;
        
        */
        
    }
    
    void buildCumMat()
    {
        cumuMat[0][0] = matCop[0][0];
        for(int i=1; i < col; i++)
        {
            cumuMat[0][i] = cumuMat[0][i-1] + matCop[0][i];
        }
        
        for(int i = 1; i < row; i++)
        {
            cumuMat[i][0] = cumuMat[i-1][0] + matCop[i][0];
        }
        
        for(int i = 1; i < row; i++)
        {
            for(int j = 1; j < col; j++)
            {
                cumuMat[i][j] = cumuMat[i-1][j] + cumuMat[i][j-1] - cumuMat[i-1][j-1] + matCop[i][j];
            }
        }
        
    }
    
    
    
    
};