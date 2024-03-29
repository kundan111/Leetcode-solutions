class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s_final = gen(s), t_final = gen(t);
        
        
        // cout << "s_final: " << s_final << endl << "t_final: " << t_final << endl;
        
        return s_final == t_final;
    }
    
    string gen(string &s)
    {
        int i = 0;
        int sz = s.size();
        
        string s_final = "";
        
         while(i < sz)
        {
            char c = s[i];
            if(c != '#')
            {
                s_final += c;
                i++;
            }else{
                
                while(i < sz && s[i] == '#')
                {
                    if(s_final.size())
                    {
                        s_final.pop_back();
                    }
                    i++;
                }
                
            }
            
            
        }
        
        return s_final;
    }
};