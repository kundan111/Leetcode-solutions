class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long int i = 0; i*i <= c; i++)
        {
            if(isSquare(c - (long long)i*i))
                return true;
        }
        return false;
    }
    
    bool isSquare(long long int n)
    {
        
        return ceil((double)sqrt(n)) == floor((double)sqrt(n));
    }
    
};