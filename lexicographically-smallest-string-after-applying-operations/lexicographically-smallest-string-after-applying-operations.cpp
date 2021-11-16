class Solution {
private:
    string res;
public:
    string findLexSmallestString(string s, int a, int b) {
        
        
        res = s;
        
        unordered_set<string> st;
        dfs(s,a,b,st);
        
        
        return res;
        
        
    }
    
    string add(string s, int a)
    {
        string ret = "";
        int sz = s.size();
        for(int i = 0; i < sz; i++)
        {
            if(i%2)
            {
                ret += (((s[i] - '0') + a) % 10) + '0';
            }else{
                ret += s[i];
            }
        }
        
        return ret;
    }
    
    string rot(string s, int b)
    {
        string ret = "";
        int sz = s.size();
        
        ret += s.substr(sz-b);
        ret += s.substr(0,sz-b);
        
        return ret;
    
    }
    
    void dfs(string s, int a, int b, unordered_set<string> &st)
    {
        // cout << "yo" << endl;
        if(st.find(s) != st.end())
        {
            return;
        }
        st.insert(s);
        res = min(res,s);
        
        dfs(add(s,a), a , b, st);
        dfs(rot(s,b), a , b, st);
        
    }
    

    
};