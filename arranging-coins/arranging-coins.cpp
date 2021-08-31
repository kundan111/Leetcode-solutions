class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1;
        int r = n;
        
        int ret;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            long long int pote_sum = (long long )mid*(mid+1)/2;
            
            if(pote_sum == n)
            {
                return mid;
            }else if(pote_sum > n)
            {
                r = mid-1;
            }else{
                ret = mid;
                l = mid+1;
            }
            
        }
        
        return ret;
    }
};