class Solution {
private:
    int startX;
    int startY;
    int row;
    int col;
    int len;
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        
        startX = startPos[0];
        startY = startPos[1];
        len = s.size();
        row = n;
        col = n;
        
        vector<int> result(len);
        for(int i = 0; i < len; i++)
        {
            int res = 0;
            walk(i,res,startX,startY,s);
            result[i] = res;
        }
        
        return result;
        
        
        
    }
    
    void walk(int curIndex, int &res, int curRow, int curCol, string &s)
    {
        if(!isValid(curRow,curCol))
        {
            return;
        }
        
        for(int i = curIndex; i < len; i++)
        {
            if(s[i] == 'L'){
                curCol--;
            }else if(s[i] == 'R')
            {
                curCol++;
            }else if(s[i] == 'U')
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
    
    bool isValid(int x, int y)
    {
        return ((x >= 0 && x < row) && (y >= 0 && y < col));
    }
};

// T.C -> O(N^2)