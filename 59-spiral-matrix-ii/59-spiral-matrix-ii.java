class Solution {
   public int[][] generateMatrix(int n) {
        
        int[][] matrix = new int[n][n];

        int rowStart = 0;
        int rowEnd = n-1;

        int colStart = 0;
        int colEnd = n-1;


        int counter = 1;
        while (rowStart <= rowEnd && colStart <= colEnd) {
            // print top row

            for (int i = colStart; i <= colEnd; i++) {
                matrix[rowStart][i] = counter;
                counter++;
            }

            rowStart++;

            // print right column

            for (int i = rowStart; i <= rowEnd; i++) {
                matrix[i][colEnd] = counter;
                counter++;
            }
            
            colEnd--;


            /*
            Take a 1X3 matrix, and go through the code, you'll find that if you don't add rowBegin<=rowEnd you'll keep adding duplicated elements into your list, 
            since when the range of rows expired, the loop for col can still go on.
            */
            if(rowStart <= rowEnd)
            {
                // print bottom row
                for (int i = colEnd; i >= colStart; i--) {
                    matrix[rowEnd][i] = counter;
                    counter++;
                }
            }

            rowEnd--;

            if(colStart <= colEnd)
            {

                // print left column
                for (int i = rowEnd; i >= rowStart; i--) {
                    matrix[i][colStart] = counter;
                    counter++;
                }
            }
            

            colStart++;
        }
     
     
     
        return matrix;
    }
}