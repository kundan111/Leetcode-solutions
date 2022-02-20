class Solution {
        public int countNegatives(int[][] grid) {

        int row = grid.length; // 4
        int col = grid[0].length; // 4

        int startRow = row - 1; // 3
        int startCol = 0; // 0

        int res = 0;
        while (startRow >= 0 && startCol < col) {
            if(grid[startRow][startCol] < 0)
            {
                res += col - startCol ;
                startRow--;
            }else{
                startCol++;
            }
        }


        return res;
    }
}