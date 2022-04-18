class Solution {
    public int kthSmallest(int[][] matrix, int k) {
     
        
        int row = matrix.length;
        int col = matrix[0].length;

        int[] res = new int[row*col];

        int index = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                res[index++] = matrix[i][j];
            }
        }

        

        Arrays.sort(res);


        return res[k-1];
        
    }
}