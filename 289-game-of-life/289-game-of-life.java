class Solution {
    int row;
    int col;

    int[] offSetX = {-1,1,0,0,-1,-1,1,1};
    int[] offSetY = {0,0,-1,1,-1,1,-1,1};

    public void gameOfLife(int[][] board) {
        approach1(board);
    }

    void approach1(int[][] board)
    {
        row = board.length;
        col = board[0].length;

        int[][] newGrid = new int[row][col];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                
                int[] cellCount = getNeighboursDeadAndLiveCellCount(board, i, j);
                
                if(board[i][j] == 1)
                {
                    if(cellCount[1] < 2)
                    {
                        newGrid[i][j] = 0;
                    }else if(cellCount[1] == 2 || cellCount[1] == 3)
                    {
                        newGrid[i][j] = 1;
                    }else{
                        newGrid[i][j] = 0;
                    }
                }else{
                    if(cellCount[1] == 3) 
                    {
                        newGrid[i][j] = 1;
                    }else{
                        newGrid[i][j] = 0;
                    }
                }



            }
        }


//         board = null;
//         board = newGrid;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                board[i][j] = newGrid[i][j];
            }
            
        }

    }

    boolean isWithin(int i, int j)
    {
        return ((i >= 0 && i < row) && (j >= 0 && j < col));
    }

    int[] getNeighboursDeadAndLiveCellCount(int[][] board, int i, int j)
    {
        int[] ret = new int[2];

        int oneCount = 0;
        int zeroCount = 0;

        for (int k = 0; k < 8; k++) {
            int newX = i + offSetX[k];
            int newY = j + offSetY[k];

            if(isWithin(newX, newY))
            {
                if(board[newX][newY] == 0)
                {
                    zeroCount++;
                }else{
                    oneCount++;
                }
            }
        }

        ret[0] = zeroCount;
        ret[1] = oneCount;
        return ret;
    }
}