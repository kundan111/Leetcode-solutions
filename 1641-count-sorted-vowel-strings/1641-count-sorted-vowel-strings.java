class Solution {
    public int countVowelStrings(int n) {
        int res = 0;
        for (int i = 0; i < 5; i++) {
            res += generate(i, n-1,0);
            
        }
        return res;
    }
    
    int generate(int curIndex, int n, int curLen)
    {
        if(curLen == n)
        {
            
            return 1;
        }

        int sum = 0;
        for (int i = curIndex; i < 5; i++) {
            sum += generate(i, n,curLen+1);
        }

        return sum;



    }
}