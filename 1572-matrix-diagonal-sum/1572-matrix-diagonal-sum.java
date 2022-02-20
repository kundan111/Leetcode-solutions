class Solution {
    public int diagonalSum(int[][] mat) {
        
        int edge = mat.length;
        int res = 0;
        for (int i = 0; i < edge; i++) {
            for (int j = 0; j < edge; j++) {
                if(i == j)
                {
                    res += mat[i][j];
                }
                if( i + j == edge - 1)
                {
                    res += mat[i][j];
                }
            }
        }
        
        return edge%2 == 1 ? res - mat[edge/2][edge/2] : res;
    }
}