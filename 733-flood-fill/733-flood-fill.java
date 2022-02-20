class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {

        int[][] visited = new int[image.length][image[0].length];
        int oldcolor = image[sr][sc];
        floodFillUtil(image, visited, sr, sc, oldcolor,  newColor); 

        return image;
    }

    void floodFillUtil(int[][] image, int[][] visited, int i, int j, int oldcolor, int newColor) {
        
        if(!within(i,j,image.length, image[0].length) || visited[i][j] == 1)
        {
            return;
        }

        visited[i][j] = 1;
        if(image[i][j] == oldcolor)
        {
            image[i][j] = newColor;
        }else{
            return;
        }
        
        floodFillUtil(image, visited, i, j+1,oldcolor, newColor);
        floodFillUtil(image, visited, i, j-1,oldcolor, newColor);
        floodFillUtil(image, visited, i-1, j,oldcolor, newColor);
        floodFillUtil(image, visited, i+1, j,oldcolor, newColor);
        
}


    private boolean within(int i, int j, int row, int col) {
        
        return ((i >=0 && i < row) && (j >= 0 && j < col));

    }
}