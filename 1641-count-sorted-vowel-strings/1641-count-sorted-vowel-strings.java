class Solution {
    int res;
    
    public int countVowelStrings(int n) {
        
        for (int i = 0; i < 5; i++) {
            generate(i, n-1,0);
            
        }


        return res;
    }

    void generate(int curIndex, int n, int curLen)
    {
        if(curLen == n)
        {
            res += 1;
            return;
        }

        for (int i = curIndex; i < 5; i++) {
            generate(i, n,curLen+1);
        }

    }
}