class Solution {
public:
    bool isValid(string str) {
         int n = str.size();
    stack<char>s;
    map<char,char>m;
    
    m.insert(make_pair(')','('));
    m.insert(make_pair('}','{'));
    m.insert(make_pair(']','['));
    
    if(n & 1)
        return false;
    
    
    for(int i = 0; i < n; i++)
    {
        char c = str[i];
        if( c == ')' || c == '}' || c == ']')
        {
            char top = (s.empty() == false) ? s.top() : '#';
            s.pop();
            
            if(top != m[c])
                return false;
        }else
            s.push(c);
        
    }
    
    return (s.empty());
    }
};