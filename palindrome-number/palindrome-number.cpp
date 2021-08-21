class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0)
            return 1;
        
        if( x < 0 || x % 10 == 0)
        {
            return 0;
        }
        
        long long int rev = 0;
        int copy = x;
        
        while(x)
        {
            int last = x%10;
            rev = rev*10 + last;
            x = x/10;
        }
        
        return rev == copy;
        
        
    }
};