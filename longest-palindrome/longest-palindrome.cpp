class Solution {
public:
    int longestPalindrome(string s) {
        
        int oddCount = 0;
        int sz = s.size();
        for(auto i = 'A'; i <= 'z'; i++)
        {
            oddCount += count(s.begin(),s.end(),i) & 1;
        }
        
        return oddCount == 0 ? s.size() : s.size() - oddCount + 1;
    
    }
};