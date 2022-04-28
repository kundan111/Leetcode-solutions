class Solution {
    int row;
    int col;

    public int minimumEffortPath(int[][] heights) {
        

        row = heights.length;
        col = heights[0].length;

        int l = 0;
        int r = Integer.MAX_VALUE;
        int ans = Integer.MAX_VALUE;
        while (l<= r) {
            
            boolean[][] visited = new boolean[row][col];
            int mid = l + (r-l)/2;
            if(dfs(heights, 0, 0, mid, visited))
            {
                ans = Math.min(ans, mid);
                r = mid-1;
            }else{
                l = mid+1;
            }


        }

        return ans;
    
    }

    boolean dfs(int[][] heights, int curX, int curY, int cur_diff, boolean[][] visited)
    {

        if(curX == row - 1 && curY == col - 1)
        {
            return true;
        }
        int curVal = heights[curX][curY];
        visited[curX][curY] = true;

        boolean isPathPossible = false;

        if(isWithin(curX, curY+1) && Math.abs(curVal -  heights[curX][curY+1]) <= cur_diff && !visited[curX][curY+1])
        {
            isPathPossible = isPathPossible || dfs(heights, curX, curY+1, cur_diff,visited);
        }

        if(isWithin(curX+1, curY) && Math.abs( curVal -  heights[curX+1][curY] ) <= cur_diff && !visited[curX+1][curY])
        {
            isPathPossible = isPathPossible || dfs(heights, curX+1, curY, cur_diff,visited);
        }

        if(isWithin(curX, curY-1) && Math.abs( curVal -  heights[curX][curY-1] ) <= cur_diff && !visited[curX][curY-1])
        {
            isPathPossible = isPathPossible || dfs(heights, curX, curY-1, cur_diff,visited);
        }

        if(isWithin(curX-1, curY) && Math.abs( curVal -  heights[curX-1][curY] ) <= cur_diff && !visited[curX-1][curY])
        {
            isPathPossible = isPathPossible || dfs(heights, curX-1, curY, cur_diff,visited);
        }



        return isPathPossible;

        
    }

    boolean isWithin(int i, int j)
    {
        return (i >= 0 && i < row) && (j >= 0 && j < col);
    }
}