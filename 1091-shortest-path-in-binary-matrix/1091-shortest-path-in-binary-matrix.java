class Coordinate{
    int x;
    int y;

    public Coordinate(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public String toString() {
        return "[" + x + "," + y + "]";
    }

}
class Solution {
    

    int edgeLen;

    int[] offSetX = {-1,-1,1,1,-1,1,0,0};
    int[] offSetY = {-1,1,-1,1,0,0,-1,1};

    int ans = Integer.MAX_VALUE;

    public int shortestPathBinaryMatrix(int[][] grid) {
        edgeLen = grid.length;

        // dfs(0, 0, grid, 0);


        // return ans == Integer.MAX_VALUE ? -1 : ans+1;
        int temp = bfs(grid);
        return temp != -1 ? temp+1 : -1;
        
    }

    void dfs(int i, int j, int[][] grid, int curPathLen)
    {
        // System.out.println("dfs(" + i + "," + j + ",grid," + curPathLen + ");");
        if(i == edgeLen-1 && j == edgeLen-1)
        {
            // reached destination
            if(grid[i][j] == 0)
            {
                ans = Math.min(ans, curPathLen);
            }
            return;
        }

        // if not valid return
        if(!isValid(grid, i, j))
        {
            return;
        }

        // mark that cell as visited
        grid[i][j] = 2;

        for (int k = 0; k < 8; k++) {
            int nextX = i + offSetX[k];
            int nextY = j + offSetY[k];

                dfs(nextX, nextY, grid, curPathLen+1);
        }

        // mark that cell as unvisited
        grid[i][j] = 0;

    }

    boolean isValid(int[][] grid,int i,int j)
    {
        return (((i >= 0 && i < edgeLen) && (j >=0 && j < edgeLen)) && (grid[i][j] == 0));
    }

    int bfs(int[][] grid)
    {

        if(grid[0][0] != 0)
        {
            return -1;
        }

        Queue<Coordinate> q = new LinkedList<>();
        q.add(new Coordinate(0, 0));
        grid[0][0] = 2;
        int curDist = 0;
        while (!q.isEmpty()) {
            
            int sz = q.size();
            

            while (sz-- > 0) {

                // System.out.println(q);
                // System.out.println("curDist: " + curDist);
                
                Coordinate curCoordinate = q.poll();
                if(curCoordinate.x == edgeLen-1 && curCoordinate.y == edgeLen-1)
                {
                    return curDist;
                    // if(grid[edgeLen-1][edgeLen-1] == 0)
                    // {
                    // }else{
                    //     return -1;
                    // }
                }

                // mark the cur node
                // grid[curCoordinate.x][curCoordinate.y] = 2;

                
                for (int i = 0; i < 8; i++) {
                    int nextX = curCoordinate.x + offSetX[i];
                    int nextY = curCoordinate.y + offSetY[i];

                    if(isValid(grid, nextX ,nextY))
                    {
                        grid[nextX][nextY] = 2;
                        q.add(new Coordinate(nextX, nextY));
                    }
                }

                // printGrid(grid);

                

            }
            curDist++;


        }        

        return -1;

    }

    void printGrid(int[][] grid)
    {
        int row = grid.length;
        int col = grid[0].length;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                System.out.print(grid[i][j] + " ");
            }
            System.out.println();
        }

    }
}