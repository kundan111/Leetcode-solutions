// I could not solve this problem peeked solution of ygalkin
class Solution {
    private:
        unordered_map<char,int> m = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
    
public:
    int romanToInt(string s) {
        int res = 0;
        int prev = 0;
        int cur = 0;
        
        int sz = s.size();
        int i = 0 ;
        
        for(i = sz-1; i >= 0; i--)
        {
            cur = m[s[i]];
            res = (i < sz-1 && cur < prev) ? res - cur : res + cur;
            prev = cur;
        }
        
        return res;
    }
};