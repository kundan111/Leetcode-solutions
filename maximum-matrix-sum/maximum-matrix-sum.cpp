class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& m) {
        int row = m.size();
        int col = m[0].size();
        long long int sum = 0;
        int minEle = INT_MAX;
        int negCount = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                sum += abs(m[i][j]);
                
                if(m[i][j] < 0)
                    negCount++;
                minEle = min(minEle , abs(m[i][j]));
            }
        }
        
        return negCount % 2 == 0 ? sum : sum - 2*minEle;
    }
};