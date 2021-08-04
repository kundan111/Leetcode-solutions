class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        
        
        int row = mat.size();
        int col = mat[0].size();
        
        if(target == mat)
            return true;
        
        
        vector<vector<int>> temp(row,vector<int> (col, 0));
        for(int i = 0; i < 3; i++)
        {
            
            for(int r = 0; r < row; r++)
            {
                for(int c = 0; c < col; c++)
                {
                    temp[c][row-1-r] = mat[r][c];
                }
            }
            
            if(temp == target)
                return true;
            mat = temp;
            
        }
        
        return false;
    }
};