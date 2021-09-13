class Solution {
private:
    unordered_map<int,int>m;
public:
    int maxProduct(string& s) {
        generateAllSubsequence(s);

        int res = 1;
        
        for(auto &val1: m)
        {
            for(auto &val2: m)
            {
                if((val1.first & val2.first) == 0)
                {
                    res = max(res,val1.second*val2.second);
                }
            }   
        }
        
    return res;
}
    
    void generateAllSubsequence(string s)
    {
        int sz = s.size();
        for(int i = 1; i < (1 << sz); i++)
        {
            string temp = giveStrEqiv(s,i);
            if(isPalindrome(temp))
            {
                m[i] = temp.size();
            }

        }

    }

    string giveStrEqiv(string &s, int mask)
    {
        string ret = "";
        int sz = s.size();
        for(int i = 0; i < sz; i++)
        {
            if((1 << i) & mask)
            {
                ret += s[i];
            }
        }
        return ret;
    }

    bool isPalindrome(string &s)
    {
        int sz = s.size();

        int l = 0;
        int r = sz-1;


        while(l < r)
        {
            if(s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }

        return true;

    }
};