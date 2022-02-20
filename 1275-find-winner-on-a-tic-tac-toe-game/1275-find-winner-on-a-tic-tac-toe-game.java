class Solution {
    public String tictactoe(int[][] moves) {
        
        int[][] chessboard = new int[3][3];

        boolean flag = true;
        for (int[] move : moves) {
            int x = move[0];
            int y = move[1];
            if(flag)
            {
                chessboard[x][y] = 1;
            }else{
                
                chessboard[x][y] = 2;
            }
            flag  = !flag;
        }

        // check rows and cols
        int checkRowsColsAndDiagonalsRes = checkRowsColsAndDiagonals(chessboard);
        if( checkRowsColsAndDiagonalsRes != 0)
        {
            return checkRowsColsAndDiagonalsRes == 1 ? "A" : "B";
        }

        if(checkRowsColsAndDiagonalsRes == 0 && moves.length == 9)
        {
            return "Draw";
        }


        
        return "Pending";


    }

    int  checkRowsColsAndDiagonals(int[][] chessboard)
    {

        for (int i = 0; i < 3; i++) {
            int checkRowRes = checkRow(chessboard, i);
            int checkColRes = checkCol(chessboard, i);
            if(checkRowRes != 0 || checkColRes != 0)
            {
                if(checkRowRes != 0)
                {
                    return checkRowRes;
                }
                if(checkColRes != 0)
                {
                    return checkColRes;
                }
                
            }
        }

        int checkDiagonalRes = checkDiagonal(chessboard);
        if(checkDiagonalRes != 0)
        {
            return checkDiagonalRes;
        }

        return 0;
    }
    

    int checkDiagonal(int[][] chessboard)
    {
        if(chessboard[0][0] == 0 && chessboard[0][2] == 0)
        {
            return 0;
        }

        if(chessboard[0][0] == chessboard[1][1] && chessboard[1][1] == chessboard[2][2])
        {
            return chessboard[0][0];
        }

        if(chessboard[0][2] == chessboard[1][1] && chessboard[1][1] == chessboard[2][0])
        {
            return chessboard[0][2];
        }

        return 0; 
    }

    int checkRow(int[][] chessboard,int rowNumber)
    {
        int prev = chessboard[rowNumber][0];
        if(prev == 0)
        {
            return 0;

        }
        for (int i = 0; i < 3; i++) {
            if(chessboard[rowNumber][i] != prev)
            {
                return 0;
            }
        }

        return prev;
    }

    int checkCol(int[][] chessboard, int colNumber)
    {
        int prev = chessboard[0][colNumber];
        if(prev == 0)
        {
            return 0;

        }
        for (int i = 0; i < 3; i++) {
            if(chessboard[i][colNumber] != prev)
            {
                return 0;
            }
        }

        return prev;
    }
}