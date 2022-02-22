class Solution {
    
    int res = 0;
    int row;
    int col;
    int MOD = 1000000007;
    public int uniquePaths(int m, int n)
    {
        row = m;
        col = n;

        int[][] cache = new int[row][col];

        for (int[] arr : cache) {
            Arrays.fill(arr, -1);
        }

        int result = numberOfPathsUtil(0, 0, m, n, cache);

        return result;
    }

    int numberOfPathsUtil(int i, int j, int m, int n, int[][] cache)
    {
        
        // reached at the bottom of the grid
        if(i == m-1 && j == n-1)
        {
            return 1;
        }

        if(!isValid(i, j))
        {
            // point outside the grid 
            return 0;
        }

        if(cache[i][j] != -1)
        {
            return cache[i][j];
        }

        return cache[i][j] = numberOfPathsUtil(i, j+1, m, n,cache) + numberOfPathsUtil(i+1, j, m, n,cache);



    }

    boolean isValid(int i, int j)
    {
        return ((i >= 0 && i < row) && (j >=0 && j < col));
    }
}