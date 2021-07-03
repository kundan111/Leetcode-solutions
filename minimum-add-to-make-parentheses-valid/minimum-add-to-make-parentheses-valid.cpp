class Solution {
public:
    int minAddToMakeValid(string s) {
        int l = 0, r = 0;
        for(auto c: s)
        {
            if(c == '(')
            {
                r++;
            }else if(r)
            {
                r--;
            }else{
                l++;
            }
        }
        
        return l+r;
    }
};