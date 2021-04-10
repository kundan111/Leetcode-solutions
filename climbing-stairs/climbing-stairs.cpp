class Solution {
public:
    long long int cache[46] = {0};
    int climbStairs(int n) {
        cache[1] = 1;
        cache[2] = 2;
        return (int)climbStairsHelper(n);
    }
private:
    long long int climbStairsHelper(int n) {
        if(n < 0)
            return 0;
        
        if(cache[n] != 0)
            return cache[n];
        
        long long int l = climbStairs(n-1);
        cache[n-1] = l;
        long long int r = climbStairs(n-2);
        cache[n-2] = r;

        return l + r;

    }
};

