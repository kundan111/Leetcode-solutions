class Solution {
public:
    int fib(int n) {
        
        if(n == 0 || n == 1)
            return n;
        
        vector<int>f(n+1,-1);
        
        f[0] = 0;
        f[1] = 1;
        
        
        helper(f,n);
        
        
        return f[n];
        
    }
    
    
    int helper(vector<int> &f, int n)
    {
        
        if(n == 0 || n == 1)
            return n;
        if(f[n] != -1)
        {
            return f[n];
        }
        f[n]  = helper(f,n-1) +helper(f,n-2);
        return f[n];
    }
};