class Solution {
public:
    int tribonacci(int n) {
        vector<int>fib(n+1,-1);
        if(n == 0 || n == 1)
            return n;
        else if(n == 2)
            return 1;
        
        fib[0] = 0;
        fib[1] = 1;
        fib[2] = 1;
        
        
        calculate(n,fib);
        
        return fib[n];
    }
    
    int calculate(int n, vector<int> &fib)
    {
        if(fib[n] != -1)
            return fib[n];
        
        return fib[n] = calculate(n-1,fib) + calculate(n-2,fib) + calculate(n-3,fib);
    }
};