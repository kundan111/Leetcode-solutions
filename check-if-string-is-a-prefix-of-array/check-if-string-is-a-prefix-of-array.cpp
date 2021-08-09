class Solution {
public:
    bool isPrefixString(string s, vector<string>& w) {
        int i = 0, j = 0;
        int sz = s.size();
        int wz = w.size();
        
        
        while(i < sz && j < wz)
        {
            int k = 0;
            int curWordSize = w[j].size();
            while(i < sz && k < curWordSize && s[i] == w[j][k])
            {
                i++;
                k++;
            }
            if( k != curWordSize)
            {
                return false;
            }
            if(k == curWordSize && j == wz)
            {
                return false;
            }
            j++;
        }
        
        if(i != sz)
        {
            return false;
        }
        
        return true;
    }
};