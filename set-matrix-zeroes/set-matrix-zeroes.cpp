class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int row = m.size();
        int col = m[0].size();
        
        
        set<int> zero_row,zero_col;
        
        for(int i = 0; i < row;i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(m[i][j] == 0)
                {
                    zero_row.insert(i);
                    zero_col.insert(j);
                }
            }
        }
        
        
        for(auto &pr: zero_row)
        {
            for(int i =0 ; i < col ; i++)
            {
                m[pr][i] = 0;
            }
        }
        
        for(auto &pr: zero_col)
        {
             for(int i =0 ; i < row ; i++)
            {
                m[i][pr] = 0;
            }
        }
    }
};