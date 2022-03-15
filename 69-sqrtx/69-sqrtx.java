class Solution {
   public int mySqrt(int x) {
       
       if(x == 0)
        {
            return 0;
           
        }
       
        int l = 1;
        int r = x;

        int poten = -1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if((long)mid*mid == x)
            {
                return mid;
            }
            if((long)mid*mid < x)
            {
                poten = mid;
                l = mid +1;
            }else{
                r = mid -1;
            }
        }
        

        return poten;
       
    }
}