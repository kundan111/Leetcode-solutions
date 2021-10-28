class Solution {
public:
    string removeOuterParentheses(string s) {
                
        stack<char>st;
        int sz = s.size();
        string res = "";
        for(int i = 0; i < sz; i++)
        {
            char cur = s[i];
            if(cur == '(')
            {
                if(st.size())
                {
                    res += cur;
                }
                st.push(cur);
            }else{
                st.pop();
                if(st.size())
                {
                    res += cur;  
                }
            }
        }
        
        return res;
    }
};