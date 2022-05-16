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


    public int shortestPathBinaryMatrix(int[][] grid) {
        edgeLen = grid.length;
        int temp = bfs(grid);
        return temp != -1 ? temp+1 : -1;
        
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
        grid[0][0] = 1;
        int curDist = 0;
        while (!q.isEmpty()) {
            
            int sz = q.size();
            
            while (sz-- > 0) {

                Coordinate curCoordinate = q.poll();
                if(curCoordinate.x == edgeLen-1 && curCoordinate.y == edgeLen-1)
                {
                    return curDist;
                }

                for (int i = 0; i < 8; i++) {
                    int nextX = curCoordinate.x + offSetX[i];
                    int nextY = curCoordinate.y + offSetY[i];

                    if(isValid(grid, nextX ,nextY))
                    {
                        grid[nextX][nextY] = 1;
                        q.add(new Coordinate(nextX, nextY));
                    }
                }

            }
            curDist++;
        }        

        return -1;
        
    }

    
}