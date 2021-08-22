class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int sz = nums.size();
        map<int,int>m;
        for(string &s: nums)
        {
            int curInt = binToInt(s);
            m[curInt]++;
        }
        
        int s = 0;
        int e = (2 << sz) -1;
        
        
        for(auto i = m.begin(); i != m.end(); i++)
        {
            if(i->first != s)
            {
                return intToString(s,sz);
            }
            s++;
        }
        
        return intToString(s,sz);
    }
    
    int binToInt(string &s)
    {
        int res = 0;
        int len = s.size();
        
        int c = 0;
        for(int i = len-1; i >= 0; i--)
        {
            res += (s[i] - '0')*(1 << c);
            c++;
        }
        return res;
    }
    
    string intToString(int i, int sz)
    {
        string res = "";
        while(i)
        {
            int last = i%2;
            res += to_string(last);
            i = i/2;
        }

        reverse(res.begin(),res.end());
        
        int res_len = res.size();
        if(res_len < sz)
        {
            res = string(sz-res_len,'0') + res;
        }
        
        return res;

    }
};