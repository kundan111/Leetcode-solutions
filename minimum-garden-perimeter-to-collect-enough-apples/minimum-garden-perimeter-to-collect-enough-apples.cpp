class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long int myApples = 0;
        int start = 0;
        while(myApples < neededApples)
        {
            start++;
            myApples += applesInPermiter(start);
            
        }
        
        return (1LL)*8*start;
    }
    
    long long int applesInPermiter(int n)
    {
        long long a = 8*1LL*n;
        long long b = 4*1LL*n;
        
        long long c = 0;
        
        //optimize this for loop
        // for(int i = 1; i <= n-1; i++)
        // {
        //     c += (n+i);
        // }
        
        c= (1LL)*(n-1)*n + (1LL)*n*(n-1)/2;
        
        c = 1LL*8*c;
        
        return 1LL*(a + b + c);
    }
    
    
};