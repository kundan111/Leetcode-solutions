class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int md = 0;
        
        for(char c: s)
        {
            
            
            if(c == '(')
            {
                st.push(c);
                if(st.size() > md)
                {
                    md = st.size();
                }
                
            }else if(c == ')'){
                if(st.top() == '(')
                {
                    st.pop();
                }
            }else{
                
                continue;
            }
            
        }
        
        
        
        return md;
        
    }
};