class Solution {
    
    int row;
    int col;

    boolean result = false;
    public boolean exist(char[][] board, String word) {
        row = board.length;
        col = board[0].length;

        boolean[][] visited = new boolean[row][col];

        /*
        int count = 0;
        for (boolean[] bs : visited) {
            System.out.println(count++);
            System.out.println("sdfsd");
            System.out.println(Arrays.toString(bs));
        }
        */
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(board[i][j] == word.charAt(0))
                {
                    if(result)
                    {
                        break;
                    }
                    dfs(board, visited, i, j, 0, word);
                }
            }
            
        }

        return result;
    }
    void dfs(char[][] board, boolean[][] visited, int curI, int curJ, int curWordPos, String word)
    {
        if(result)
        {
            return;
        }
        if(!isValid(curI, curJ) || curWordPos >= word.length())
        {
            return;
        }
        
        if(visited[curI][curJ])
        {
            return;
        }
        

        if(word.charAt(curWordPos) != board[curI][curJ])
        {
            return;
        }
        if(curWordPos == word.length()-1)
        {
            result = true;
            return;
        }

        // mark the cell visited 
        visited[curI][curJ] = true;

        dfs(board, visited, curI, curJ+1, curWordPos+1, word);
        
        dfs(board, visited, curI+1, curJ, curWordPos+1, word);
        dfs(board, visited, curI, curJ-1, curWordPos+1, word);
        dfs(board, visited, curI-1, curJ, curWordPos+1, word);

        visited[curI][curJ] = false;


        
    }

    boolean isValid(int i, int j)
    {
        return ((i >= 0 && i < row) && (j >= 0 && j < col));
    }
}