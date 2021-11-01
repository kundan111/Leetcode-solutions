class Solution {
private:
    int row, col;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int total_oranges = 0;
        int rotten_oranges = 0;
        int fresh_oranges = 0;
        row = grid.size();
        col = grid[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == 1)
                {
                    fresh_oranges++;   
                }
                
                if(grid[i][j] == 2)
                {
                   rotten_oranges++;
                    q.push({i,j});
                }
            }
        }
        
        
        total_oranges = rotten_oranges + fresh_oranges;
        
        int count = rotten_oranges;
        
        int dirA[4] = {0, 0 , -1, 1};
        int dirB[4] = {1, -1 , 0, 0};
        int minutes = 0;
        
        
        while(!q.empty())
        {
            
            int sz = q.size();
            
            while(sz--)
            {
            
                auto cur = q.front();
                q.pop();

                for(int i = 0; i < 4; i++)
                {
                    int new_row = cur.first + dirA[i];
                    int new_col = cur.second + dirB[i];

                    if(!(isValid(new_row,new_col) && grid[new_row][new_col] == 1))
                    {
                        continue;
                    }

                    grid[new_row][new_col] = 2;
                    q.push({new_row,new_col});
                    count++;
                }
            }
            
            if(!q.empty())
            {
                minutes++;
            }
            
        }
        
        return count != total_oranges ? -1 : minutes;
    }
    
    bool isValid(int i, int j)
    {
        return ((i >= 0 && i < row) && (j >= 0 && j < col));
    }
    
    
};