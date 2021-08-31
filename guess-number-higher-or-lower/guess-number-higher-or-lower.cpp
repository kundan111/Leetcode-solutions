/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int h = n;
        
        long long int whatIguessed = l + (h-l)/2;
        long long int res = guess(whatIguessed);
        while(l <= h)
        {
            // res = guess((l + h)/2);
            res = guess(l + (h-l)/2);
            
            
            whatIguessed = l + (h-l)/2;
            // cout << "l: " << l << endl << "h: " << h << endl << "whatIguessed: " << whatIguessed << endl<< endl;
            
            if(res > 0)
            {
                l = whatIguessed+1;
            }else if(res < 0){
                h = whatIguessed-1;
            }else{
                return whatIguessed;
            }
            
            // cout << "l: " << l << endl << "h: " << h << endl << "whatIguessed: " << whatIguessed << endl<< endl;
        }
        
        return -1;
        
        
    }
    
    
    
    
};