class Solution {
public:
    string toLowerCase(string s) {
     
        int sz = s.size();
        for(int i = 0; i < sz; i++)
        {
            char c = s[i];
            if(isalpha(c) && isupper(c))
            {
                s[i] = tolower(c)  ;
            }
        }
        
        return s;
    }
};