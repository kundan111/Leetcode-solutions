class Solution {
public:
    string makeFancyString(string s) {
        int sz = s.size();
        int i = 0;
        
        string res = "";
        
        while( i < sz)
        {
            char c = s[i];
            int j = i;
            
            int count = 0;
            
            while(j < sz && s[j] == c)
            {
                j++;
                count++;
            }
            
            
            if(count >= 3)
            {
                // res = res + c + c;
                res.push_back(c);
                res.push_back(c);
            }else{
                while(count)
                {
                    // res = res + c;
                    
                    res.push_back(c);
                    count--;
                }
                
            }
            i = j;
        }
        
        return res;
    }
};