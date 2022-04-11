class Solution {
    
    
    int row;
    int col;
    
    int[] indexToGridCoor(int index)
    {
        int[] ret = new int[2];

        ret[0] = index/col;
        ret[1] = index % col;
        return ret;
    }


    int gridCoorToIndex(int i, int j)
    {
        return i*col + j;
    }
    
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {

        row = grid.length;
        col = grid[0].length;


        List<List<Integer>> res = new ArrayList<>();

        int[][] newGrid = new int[row][col];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int newVal = (gridCoorToIndex(i, j) + k) % (row*col);
                int[] indexToGridCoor = indexToGridCoor(newVal);

                newGrid[indexToGridCoor[0]][indexToGridCoor[1]] = grid[i][j];
            }
        }

        for (int[] is : newGrid) {
            ArrayList<Integer> al = new ArrayList<>();
            for (int val : is) {
                al.add(val);
            }
            res.add(al);
        }


        return res;
    }
}