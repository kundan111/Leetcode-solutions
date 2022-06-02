class Solution {
    public int[][] transpose(int[][] matrix) {
        
        int oriRow = matrix.length;
        int oriCol = matrix[0].length;

        int resRow = oriCol;
        int resCol = oriRow;

        int[][] res = new int[resRow][resCol];

        for (int i = 0; i < resCol; i++) {
            transposeUtilUpdateCol(matrix, res, i);
        }

        return res;
    }
    

    void transposeUtilUpdateCol(int[][] ori, int[][] res, int colNumber)
    {
        int rows = res.length;
        for (int i = 0; i < rows; i++) {
            res[i][colNumber] = ori[colNumber][i];
        }

        
    }
}