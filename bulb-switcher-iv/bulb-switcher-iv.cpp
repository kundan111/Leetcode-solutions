class Solution {
public:
    int minFlips(string target) {
        int sz = target.size();
        int res = 0;
        
        int i = 0;
        char s = '0';
        while(i < sz)
        {
           
           while(i < sz && target[i] == s)
           {
               i++;
           }
            
            res++;
           if( i == sz)
           {
               return res-1;
           }
            s = s == '1' ? '0' : '1';
        }
        
        return res;
    }
};