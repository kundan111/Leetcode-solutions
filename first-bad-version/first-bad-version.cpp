// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int l = 1;
        int r = n;
        int mid;
        
        while( l < r)
        {
             mid = l + (r-l)/2;
            bool cand = isBadVersion(mid);
            
            if(cand)
            {
                r = mid;
            }else{
                
                l = mid+1;
            }
        }
        
        
        return l;
    }
};