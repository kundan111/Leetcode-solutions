class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int res = 0;
        while(k)
        {
            k = k - smallerOrEqual(k);
            res++;
        }
        
        return res;
    }
    
    int smallerOrEqual(int n)
    {
        if(n == 1)
            return n;
        int prev1 = 1;
        int prev2 = 1;



        while( n > prev1 + prev2 )
        {
            int temp = prev1 + prev2;
            prev1 = prev2;
            prev2 = temp;
        }


        return n == (prev1 + prev2) ? n : prev2;
    }
};