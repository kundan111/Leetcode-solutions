// Brute force approach
class Solution {
public:
    string longestNiceSubstring(string s) {
        
        int sz = s.size();
        int niceMaxLen = 0;
        string retStr = "";
        
        for(int i = 0; i < sz; i++)
        {
            for(int j = i; j < sz; j++)
            {
                string temp = s.substr(i,j-i+1);
                
                if(isNice(temp))
                {
                    // cout << temp << " -> " << "true" << endl;
                    if(j-i+1 > niceMaxLen)
                    {
                        niceMaxLen = j-i+1;
                        retStr = temp;
                    }
                }
                
            }
        }
        
        
        return retStr;
        
        
    }
    
    bool isNice(string &ss)
    {
        unordered_map<char,int>m;
        for(char &c : ss)
        {
            m[c]++;
        }
        
        
        
        if(m.size() & 1)
        {
            return false;
        }
        
        int oriSize = m.size();
        
        // cout << "----------------------------------" << endl;
        
        // print(m);
        
        // size is even
        // add values of all upper case keys to lower case keys
        
        
        for(auto itr = m.begin(); itr != m.end(); )
        {
            char cur = itr->first;
            if(isupper(cur))
            {
                m[tolower(cur)] += itr->second;
                itr = m.erase(itr);
            }else{
                itr++;
            }
        }
        
        // print(m);
        
        // cout << "----------------------------------" << endl;
        
        
        
        return 2*m.size() == oriSize;
        
        
        
    }
    
    void print(unordered_map<char,int> &m)
    {
        cout  << endl;
       for(auto itr = m.begin(); itr != m.end(); itr++)
        {
            cout << itr->first << " -> " << itr->second << endl;
        }
        
        cout  << endl;
    }
};