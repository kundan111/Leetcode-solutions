class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1;
        int r = num;
        
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            long long int sq = (long long)mid*mid;
            
            if(sq == num)
            {
                return true;
            }else if(sq > num)
            {
                r = mid-1;
            }else{
                
                l = mid+1;
            }
        }
        
        return false;
    }
};