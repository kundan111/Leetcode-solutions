class Solution {
    
    private int row;
    private int col;
    

    int[] dirX = {0,0,-1,1};
    int[] dirY = {1,-1,0,0};

    

    public int maxAreaOfIsland(int[][] grid) {
        int res = 0;

        row = grid.length;
        col = grid[0].length;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(grid[i][j] == 1)
                {
                    res = Math.max(res, dfs(grid, i, j));
                }
            }
        }

     
     
     
        return res;
    }

    int dfs(int[][] grid, int i, int j)
    {
        if(!isValid(grid, i, j))
        {
            return 0;
        }

        grid[i][j] = 3;
        
        return 1 + dfs(grid,i,j+1) + dfs(grid,i+1,j) + dfs(grid,i,j-1) + dfs(grid,i-1,j);
    }

    boolean isValid(int[][] grid, int i, int j)
    {
        return ((i >=0 && i < row) && (j >=0 && j < col) && (grid[i][j] == 1));
    }
}