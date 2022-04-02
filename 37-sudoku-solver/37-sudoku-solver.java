class Solution {
    int row = 9;
    int col = 9;
    
    int[] allRows = {0,3,6};
    int[] allCols = {0,3,6};


    public void solveSudoku(char[][] board) {
        
        recur(board);

    }

    boolean recur(char[][] board)
    {

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(board[i][j] == '.')
                {
                    for(int fill = 1; fill <= 9; fill++)
                    {
                        if(!isThisPresentInRow(board,i,fill) && !isThisPresentInCol(board,j,fill) && 
                        !isThisPresentInBox(board,allRows[i/3],allCols[j/3],fill))
                        {
                            board[i][j] = (char)('0' + fill);
                            if(recur(board))
                            {
                                return true;
                            }else{
                                board[i][j] = '.';
                            }
                            
                        }
                        
                    }
                    return false;
                }
            }
        }
        return true;
    }
    


    boolean isThisPresentInRow(char[][] board, int rowNum, int target)
    {
        for(int i = 0; i < col; i++)
        {
            if(board[rowNum][i] == '.')
            {
                continue;
            }
            if(board[rowNum][i] - '0' == target)
            {
                return true;
            }
        }
        return false;
    }

    boolean isThisPresentInCol(char[][] board, int colNum, int target)
    {
        for(int i = 0; i < row; i++)
        {
            if(board[i][colNum]  == '.')
            {
                continue;
            }
            if(board[i][colNum] - '0' == target)
            {
                return true;
            }
        }
        return false;
    }

    boolean isThisPresentInBox(char[][] board, int rowNum, int colNum, int target)
    {
        for(int i = rowNum; i < rowNum + 3; i++)
        {
            for(int j = colNum; j < colNum + 3; j++)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                if(board[i][j] - '0' == target)
                {
                    return true;
                }
            }
        }
        return false;
    }
}