class Solution {
    private int startX;
    private int startY;
    private int row;
    private int col;
    private int len;
    private int res;
    public int[] executeInstructions(int n, int[] startPos, String s) {
        
        startX = startPos[0];
        startY = startPos[1];
        len = s.length();
        res = 0;
        row = n;
        col = n;
        
        int[] result = new int[len]; 
        for(int i = 0; i < len; i++)
        {
            walk(i,startX,startY,s);
            result[i] = res;
            res = 0;
        }
        
        return result;
    }
    
    public void walk(int curIndex, int curRow, int curCol, String s)
    {
        if(!isValid(curRow,curCol))
        {
            return;
        }
        
        for(int i = curIndex; i < len; i++)
        {
            if(s.charAt(i) == 'L'){
                curCol--;
            }else if(s.charAt(i) == 'R')
            {
                curCol++;
            }else if(s.charAt(i) == 'U')
            {
                curRow--;
            }else{
                curRow++;
            }
            if(isValid(curRow, curCol))
            {
                res++;
            }else{
                break;
            }
        }
        
    }
    
    public boolean isValid(int x, int y)
    {
        return ((x >= 0 && x < row) && (y >= 0 && y < col));
    }
}
