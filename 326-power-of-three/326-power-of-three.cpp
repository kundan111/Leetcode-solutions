class Solution {
public:
    bool isPowerOfThree(int n) {
          if(n <= 0)
            return false;
        
       
        int l = 0;
        int r = 19;
        
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            int poten = pow(3,mid);
            
            
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