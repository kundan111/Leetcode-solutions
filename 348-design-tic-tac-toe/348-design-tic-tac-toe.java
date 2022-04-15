class TicTacToe {
    
    private int row;
    private int col;
    private char[][] board;

    public TicTacToe(int n) {
        this.row = n;
        this.col = n;

        board = new char[row][col];
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                board[i][j] = '.';
            }
        }
    }
    
    
    public int move(int x, int y, int player) {
        char c = '@';
        if(player == 1)
        {
            c = 'X';
        }else{
            c = 'O';
        }
        
        board[x][y] = c;
        
        boolean res = isBoardWon(x,y,c);
            
        return res ? player : 0;
        
    }
    
    public boolean isBoardWon(int row, int col, char c)
    {
        return isAnyDiagonalWon(c) || isThisColWon(col, c) || isThisRowWon(row, c);
    }
    
    public boolean isThisRowWon(int rowNum, char c)
    {
        for(int i = 0; i < col; i++)
        {
            if(board[rowNum][i] != c)
            {
                return false;
            }
        }
        return true;
    }
    
    public boolean isThisColWon(int colNum, char c)
    {
        for(int i = 0; i < row; i++)
        {
            if(board[i][colNum] != c)
            {
                return false;
            }
        }
        return true;
    }
    
    public boolean isAnyDiagonalWon(char c)
    {
        return isfirstDiagonalWon(c) || isSecondDiagonalWon(c);
    }
    
    public boolean isfirstDiagonalWon(char c)
    {
        for(int i = 0; i < row; i++)
        {
            if(board[i][i] != c)
            {
                return false;
            }
        }


        return true;
    }

    boolean isSecondDiagonalWon(char c)
    {
        for(int i = 0; i < row; i++)
        {
            if(board[i][row-i-1] != c)
            {
                return false;
            }
        }
        return true;
    }
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */