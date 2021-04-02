class Solution {
public:
    bool isPalindrome(int x) {
        
        // Any -ve number can not be palindrome
        // numbers from [0-9] will always be palindrome
        
        //1. exclude -ve numbers
        
        int original = x; 
        if(x < 0)
        {
            // number is negetive
            return  false;
        }
        
        if(0 <=  x && x < 10)
        {
            // single digit
            return true;
        }
        
        // make reversed ll because reversed can be larger than original number x
        long long int reversed = 0;
        while(x)
        {
            int rem = x%10;
            reversed = reversed*10 + rem;
            x = x/10;
        }
        
        
        return reversed == original;
        
        
    }
};