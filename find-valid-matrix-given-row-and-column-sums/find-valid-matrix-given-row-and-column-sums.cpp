class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rowSize = rowSum.size();
        int colSize = colSum.size();
        vector<vector<int>> res(rowSum.size(),vector<int>(colSize,0));
        
        
        for(int i = 0; i < rowSize; i++)
        {
            for(int j = 0; j < colSize ; j++)
            {
                res[i][j] = min(rowSum[i],colSum[j]);
                rowSum[i] -= res[i][j];
                colSum[j] -= res[i][j];
            }
        }
        
        return res;
    }
};