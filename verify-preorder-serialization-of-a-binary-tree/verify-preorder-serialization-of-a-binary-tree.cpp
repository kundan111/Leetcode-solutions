class Solution {
public:
    bool isValidSerialization(string pre) {
        
        vector<string> s;
        parser(pre,s);
        
        int out = 1;
        for(string &c: s)
        {
            
                out--;
            if(out < 0)
            {
                return false;
            }
                if(c != "#")
                {
                    out+=2;
                }    
            
        }
        
        return out == 0;
    }
    
    void parser(string &s, vector<string> &v)
    {
        int sz = s.size();
        for(int i = 0; i < sz; i++)
        {
            if(s[i] != ',')
            {
                if(isdigit(s[i]))
                {
                    string temp = "";
                    while(i < sz && isdigit(s[i]))
                    {
                        temp += s[i];
                        i++;
                    }
                    
                    v.push_back(temp);
                }else{
                    v.push_back("#");
                }
            }
        }
    }
};