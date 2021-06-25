class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>m;
        for(auto i: s)
        {
            m[i]++;
        }
        
        // count number of odd counts 
        int oddCount = 0;
        for(auto i = m.begin(); i != m.end(); i++)
        {
            if(i->second & 1)
            {
                oddCount++;
            }
        }
        
        return oddCount == 0 ? s.size() : s.size() - (oddCount - 1);
    
    }
};