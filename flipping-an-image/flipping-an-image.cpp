class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& img) {
        int row = img.size();
        int col = img[0].size();
        
        for(int i = 0; i < row; i++)
        {
            int l = 0;
            while(l < col/2)
            {
                swap(img[i][l],img[i][col-l-1]);
                l++;
            }
            
            l = 0;
            while(l < col)
            {
                img[i][l] = !img[i][l];
                l++;
            }
            
        }
        
        return img;
        
        
    }
};