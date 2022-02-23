class Solution {
    public int orangesRotting(int[][] grid) {
        class Pair{
            int i;
            int j;

            Pair(int i,int j)
            {
                this.i = i;
                this.j = j;
            }

            @Override
            public String toString() {
                return "Pair [i=" + i + ", j=" + j + "]";
                
            }

        }
        int row = grid.length;
        int col = grid[0].length;

        int infected = 0;  
        int nonInfected = 0;    
        Queue<Pair> q = new LinkedList<>();  
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(grid[i][j] == 2)
                {
                    q.add(new Pair(i, j));
                    infected++;
                }else if(grid[i][j] == 1)
                {
                    nonInfected++;
                }
            }
        }
        

        int time = 0;
        while (!q.isEmpty()) {
            
            int sz = q.size();
            while (sz-- > 0) {
                
                Pair curCoor = q.poll();
                int i = curCoor.i;
                int j = curCoor.j;

                if(isValid(grid, i, j+1, row, col))
                {
                    grid[i][j+1] = 2;
                    q.add(new Pair(i, j+1));
                }
                if(isValid(grid, i, j-1, row, col))
                {
                    grid[i][j-1] = 2;
                    q.add(new Pair(i, j-1));
                }
                if(isValid(grid, i-1, j, row, col))
                {
                    grid[i-1][j] = 2;
                    q.add(new Pair(i-1, j));
                }
                if(isValid(grid, i+1, j, row, col))
                {
                    grid[i+1][j] = 2;
                    q.add(new Pair(i+1, j));
                }


            }
            if(q.size() > 0)
            {
                time++;
            }

        }

        int newInfected = 0;
        for (int i  = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(grid[i][j] == 2)
                {
                    newInfected++;
                }
            }
        }

        if(newInfected - infected == nonInfected)
        {
            return time;
        }

        return -1;
    }

    boolean isValid(int[][] grid, int i, int j, int row, int col)
    {
        return ((i >= 0 && i < row) && (j >=0 && j < col) && grid[i][j] == 1);
    }
}
