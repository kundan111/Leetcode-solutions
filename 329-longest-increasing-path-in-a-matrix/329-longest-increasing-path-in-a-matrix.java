class Solution {
    int row;
    int col;

    int[] dirX = {0,0,-1,1};
    int[] dirY = {1,-1,0,0};

    boolean[][] visited;
    int[][] maxMatrix;
    int ans = 0;

    public int longestIncreasingPath(int[][] matrix) {
        
        row = matrix.length;
        col = matrix[0].length;

        maxMatrix = new int[row][col];

        for (int[] row : maxMatrix) {
            Arrays.fill(row, -1);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if(maxMatrix[i][j] == -1)
                {
                    maxMatrix[i][j] = dfs(matrix, i, j,-1); 
                }
                ans = Math.max(maxMatrix[i][j], ans);
            }
        }

        return ans;
    }


    int dfs(int[][] matrix, int i, int j, int prevVal)
    {

        if(!isValid(i, j, matrix))
        {
            return 0;
        }

        if(matrix[i][j] <= prevVal)
        {
            return 0;
        }

        if(maxMatrix[i][j] != -1)
        {
            return maxMatrix[i][j];
        }


        int maxPathFromHere = 1;

        for (int k = 0; k < 4; k++) {
            
            int nextX = i + dirX[k];
            int nextY = j + dirY[k];

            maxPathFromHere = Math.max(1 + dfs(matrix, nextX, nextY,matrix[i][j]), maxPathFromHere);
        }

        return maxMatrix[i][j] = maxPathFromHere;

    }

    boolean isValid(int i, int j, int[][] matrix)
    {
        return ((i >= 0 && i < row) && (j >=0 && j < col));
    }

    void printMaxMatrix(int[][] arr)
    {
        int row = arr.length;
        int col = arr[0].length;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }

    }
}