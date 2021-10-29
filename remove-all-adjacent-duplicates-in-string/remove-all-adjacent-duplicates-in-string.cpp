class Solution {
public:
    string removeDuplicates(string s) {
     
        stack<char> st;
        for(char &c : s)
        {
            if(st.size())
            {
                if(st.top() == c)
                {
                    st.pop();
                    
                }else{
                    st.push(c);
                }
                
            }else{
                st.push(c);
            }
        }
        
        
        string res = "";
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};