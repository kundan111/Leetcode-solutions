class Solution {
public int[][] flipAndInvertImage(int[][] image) {
        
        int edge = image.length;

        

        for (int i = 0; i < edge; i++) {
            flipAndInvertImageUtil(image[i]);
            for (int j = 0; j < edge; j++) {
                image[i][j] = image[i][j] == 0 ? 1 : 0;
            }
        }
    

        return image;
    }

    void flipAndInvertImageUtil(int[] row)
    {
        int edge = row.length;
        for (int i = 0; i < edge/2; i++) {
            int temp = row[i];
            row[i] = row[edge-i-1];
            row[edge-i-1] = temp;
        }
    }
}