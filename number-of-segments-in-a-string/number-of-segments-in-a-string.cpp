class Solution {
public:
    int countSegments(string s) {
        
        
        
        int sz = s.size();
        int res = 0;
        int i = 0;
        
        
        int count = 0;
        for(int i = 0; i < sz; )
        {
            if(s[i] != ' ')
            {
                while(i < sz && s[i] != ' ')
                {
                    i++;
                }
                res++;
            }else{
                i++;
            }
            
        }
        
        return res;
        
    }
};