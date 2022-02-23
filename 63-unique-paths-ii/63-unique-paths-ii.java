class Solution {
   int row;
    int col;
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        
        row = obstacleGrid.length;
        col = obstacleGrid[0].length;

        int[][] cache = new int[row][col];

        for (int[] arr : cache) {
            Arrays.fill(arr,-1);
        }

        return uniquePathsWithObstaclesUtil(obstacleGrid, 0, 0,cache);

    }

    public int uniquePathsWithObstaclesUtil(int[][] obstacleGrid, int i, int j, int[][] cache) {
        
        if( (i == row - 1 && j == col - 1) && obstacleGrid[i][j] == 0)
        {
            return 1;
        }

        if(!valid(i, j))
        {
            return 0;
        }

        if(obstacleGrid[i][j] == 1)
        {
            return 0;
        }

        if(cache[i][j] != -1)
        {
            return cache[i][j];
        }



        return cache[i][j] = uniquePathsWithObstaclesUtil(obstacleGrid, i, j+1,cache) + uniquePathsWithObstaclesUtil(obstacleGrid, i+1, j,cache);
        
    }

    boolean valid(int i, int j)
    {
        return ((i >= 0 && i < row) && (j >=0 && j < col));
    }
}