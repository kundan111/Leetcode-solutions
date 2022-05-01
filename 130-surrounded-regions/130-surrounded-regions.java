class Solution {
    int[] dirX = {0,0,-1,1};
    int[] dirY = {1,-1,0,0};

    public void solve(char[][] grid) {
        int row = grid.length;
        int col = grid[0].length;

        // first row
        for(int i = 0; i < col; i++)
        {
            if(grid[0][i] == 'O')
            {
                dfs(grid, 0, i,row,col);
            }
        }

        // last row
        for(int i = 0; i < col; i++)
        {
            if(grid[row-1][i] == 'O')
            {
                dfs(grid, row-1, i,row,col);
            }
        }

        // first col
        for (int i = 0; i < row; i++) {
            if(grid[i][0] == 'O')
            {
                dfs(grid, i, 0, row, col);
            }
        }

        // last column

        for (int i = 0; i < row; i++) {
            if(grid[i][col-1] == 'O')
            {
                dfs(grid, i, col-1, row, col);
            }
        }

        // mark inner zeros as X
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(grid[i][j] == 'O')
                {
                    grid[i][j] = 'X';
                }
            }
        }


        // revert to old O which were turned into 3
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(grid[i][j] == '3')
                {
                    grid[i][j] = 'O';
                }
            }
        }
    }

    void dfs(char[][] grid, int i, int j, int row, int col)
    {
        if(validDFS(grid , i, j, row, col)){
            grid[i][j] = '3';
            

            for (int k = 0; k < 4; k++) {
                int newX = i + dirX[k];
                int newY = j + dirY[k];

                if(validDFS(grid, newX, newY, row, col))
                {
                        dfs(grid, newX, newY, row, col);
                }
            }


        }
    }
    

    boolean validDFS(char[][] grid, int i, int j, int row, int col)
    {
        return ((i >=0 && i < row) && (j >= 0 && j < col) && grid[i][j] == 'O');
    }
}