class Solution {
    public int climbStairs(int n) {
        
        return approach2(n);
        
    }
    
    public int approach2(int n) 
    {
        if(n == 1)
        {
            return 1;
        }

        if(n == 2)
        {
            return 2;
        }


        int first = 1;
        int second = 2;

        int i = 0;
        

        while (i != n-3) {
            int temp = first;
            first = second;
            second = temp + second;
            i++;
        }
        return first + second;
    }
}