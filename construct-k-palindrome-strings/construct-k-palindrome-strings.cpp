class Solution {
public:
    bool canConstruct(string s, int k) {
        
        if( k > s.size())
            return false;
        
        
        unordered_map<char,int>m;
        for(auto c: s)
        {
            m[c]++;
        }
        
        int oddCount = 0;
        for(auto i: m)
        {
            if(i.second & 1)
                oddCount++;
        }
        
        if(oddCount > k)
            return false;
        
        return true;
        
        
    }
};