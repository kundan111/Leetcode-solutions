class Solution {
    public int fib(int n) {
        

        return approach1(n);
    }

    public int approach1(int n) 
    {
       if(n == 0)
        {
            return 0;
        }

        
        if(n == 1)
        {
            return 1;
        }


        int first = 0;
        int second = 1;

        int i = 0;

        while (i != n-2) {
            int temp = first;
            first = second;
            second = temp + second;
            i++;
        }
        return first + second;
        
    }
}