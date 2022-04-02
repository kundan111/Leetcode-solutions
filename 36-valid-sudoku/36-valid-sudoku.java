class Solution {
    int row;
    int col;
    public boolean isValidSudoku(char[][] board) {
        
        row = board.length;
        col = board[0].length;


        // check row
        for(int i = 0; i < row; i++)
        {
            if(!checkRow(board,i))
            {
                // System.out.println("yo1");
                return false;
            }
        }
        
        
        // check col
        for(int i = 0; i < col; i++)
        {
            if(!checkCol(board,i))
            {
                // System.out.println("yo2");
                return false;
            }
        }
        
        // check boxes
        int[] allRows = {0,3,6};
        int[] allCols = {0,3,6};
        
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(!checkBox(board,allRows[i],allCols[j]))
                {
                    // System.out.println("yo3");
                    return false;
                }
            }
        }

        return true;
    }

    boolean checkRow(char[][] board, int rowNum)
    {
        int[] nums = new int[26];
        for(int i = 0; i < col; i++)
        {
            if(board[rowNum][i] == '.')
            {
                continue;
            }
            int curNum = board[rowNum][i] - '0';
            if(nums[curNum] > 0)
            {   
                return false;
            }
            nums[curNum] = 1;
        }
        return true;
    }

    boolean checkCol(char[][] board, int colNum)
    {
        int[] nums = new int[26];
        for(int i = 0; i < row; i++)
        {
            if(board[i][colNum] == '.')
            {
                continue;
            }
            int curNum = board[i][colNum] - '0';
            if(nums[curNum] > 0)
            {   
                return false;
            }
            nums[curNum] = 1;
        }
        return true;
    }

    boolean checkBox(char[][] board, int rowNum, int colNum)
    {
        int[] nums = new int[26];
        for(int i = rowNum; i < rowNum+3; i++)
        {
            for(int j = colNum; j < colNum+3; j++)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }

                int curNum = board[i][j] - '0';
                if(nums[curNum] > 0)
                {   
                    return false;
                }
                nums[curNum] = 1;
            }
        }

        return true;
    }
    
}