class Solution {
public:
    bool isPowerOfThree(int n) {
        
        
        if(n <= 0)
            return false;
        
        
        // int l = -1500;
        // int r = 1500;
        
        int l = 0;
        int r = 20;
        
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            long long int poten = pow(3,mid);
            
            
            if(poten == n)
            {
                return true;
            }else if(poten > n)
            {
                r =mid-1;
            }else{
                l = mid+1;
            }
        }
        
        return false;
    }
};