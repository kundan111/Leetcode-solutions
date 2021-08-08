class Solution {
public:
    string makeFancyString(string s) {
        int sz = s.size();
        int j =1;
        
        int cnt = 1;
        
        for(int i = 1; i < sz; i++)
        {
            
            cnt = s[i] == s[i-1] ? cnt+1 : 1;
            if(cnt < 3)
                
            {
                s[j++] = s[i];
            }
        }
        
        
        s.resize(j);
        
        
        return s;
    }
};