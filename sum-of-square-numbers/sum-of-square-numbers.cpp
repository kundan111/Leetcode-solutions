class Solution {
public:
    bool judgeSquareSum(int c) {
        
        long long int l = 0;
        int r = sqrt(c);
        
        while(l <= r)
        {
            long long int cur = l*l + (long long int)r*r;
            if(c < cur)
            {
                r--;
            }else if(c > cur)
            {
                l++;
            }else{
                return true;
            }
        }
        
        return false;
    }
    
    
    
};