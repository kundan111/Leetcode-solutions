class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while( l < r)
        {
            if(s[l] != s[r])
            {
                return isPalindrome(s,l+1,r) || isPalindrome(s,l,r-1);
            }
            l++;
            r--;
        }
        
        return true;
        
    }
    
    bool isPalindrome(string s, int l, int r)
    {
        if( l < s.size() && r < s.size())
        {
            s = s.substr(l,r-l+1);
            int  i = 0;
            int j = s.size()-1;
            
            
            while(i < j)
            {
                if(s[i] != s[j])
                {
                    return false;
                }
                i++;
                j--;
            }
            
            return true;
        }
        return false;
    }
};