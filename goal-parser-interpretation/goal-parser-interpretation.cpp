class Solution {
public:
    string interpret(string s) {
        string res = "" ;
        int sz = s.size();
        for(int i = 0; i < sz;)
        {
            if(s[i] == 'G')
            {
                res += 'G';
                i++;
            }else
            {
                if(i + 1 < sz && s[i+1] == ')')
                {
                    res += 'o';
                    i += 2;
                }else{
                    res += "al";
                    i += 4;
                }
            }
        }
        
        return res;
        
    }
};