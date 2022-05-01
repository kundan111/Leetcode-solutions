class Solution {
     int row;
    int col;

    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
     
        
        char[][] grid = buildGrid(m, n, guards, walls);

        row = m;
        col = n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                char curChar = grid[i][j];
                if(curChar == 'G')
                {
                    // mark cells as E 
                    guardRow(grid, j, i);
                    guardCol(grid, j, i);

                }

            }
        }

        // printGrid(grid);

        int res = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(grid[i][j] == '.')
                {
                    res++;
                }
            }
        }

        

        return res;
        
    }

    char[][] buildGrid(int m, int n, int[][] guards, int[][] walls)
    {

        char[][] grid = new char[m][n];

        for (int[] guard : guards) {
            grid[guard[0]][guard[1]] = 'G';
        }

        for (int[] wall : walls) {
            grid[wall[0]][wall[1]] = 'W';
        }


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == 'G' || grid[i][j] == 'W' )
                {
                    continue;
                }else{
                    grid[i][j] = '.';
                }
            }
        }


        // printGrid(grid);

        return grid;
        
    }
    

    void guardRow(char[][] grid, int colNum, int rowNum)
    {
        // start to that point in row
        for (int i = colNum-1; i >= 0; i--) {
            if(grid[rowNum][i] != 'W' && grid[rowNum][i] != 'G')
            {
                grid[rowNum][i] = 'E';
            }else{
                break;
            }
        }

        // point to end
        for (int i = colNum+1; i < col; i++) {
            if(grid[rowNum][i] != 'W' && grid[rowNum][i] != 'G')
            {
                grid[rowNum][i] = 'E';
            }else{
                break;
            }
        }
    }

    void guardCol(char[][] grid, int colNum, int rowNum)
    {
        for (int i = rowNum-1; i >= 0; i--) {
            if(grid[i][colNum] != 'W' && grid[i][colNum] != 'G')
            {
                grid[i][colNum] = 'E';
            }else{
                break;
            }
        }

        for (int i = rowNum+1; i < row; i++) {
            if(grid[i][colNum] != 'W' && grid[i][colNum] != 'G')
            {
                grid[i][colNum] = 'E';
            }else{
                break;
            }
        }
    }

    void printGrid(char[][] grid)
    {
        int m = grid.length;
        int n = grid[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(grid[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    boolean isValid(int i,int j)
    {
        return ((i >= 0 && i < row) && (j >=0 && j < col ));
    }
}