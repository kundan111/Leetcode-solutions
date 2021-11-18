class Solution {
public:
    int countTriples(int n) {
     
        int res = 0;
        
        int cur = n;
        int l = 1;
        int r = n-1;
        
        while(cur >= 1)
        {
            l = 1;
            r = cur-1;
            
            while(l < r)
            {
                if(l*l + r*r == cur*cur)
                {
                    res += 2;
                    l++;
                    
                    r--;
                }else if(l*l + r*r < cur*cur)
                {
                    l++;
                }else{
                    r--;
                }
            }
            cur -= 1;
            
        }
        
        return res;
        
    }
};