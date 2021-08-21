class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char t) {
        auto res = upper_bound(l.begin(),l.end(),t);
        return  res  == l.end() ? l[0] : *res; 
    }
    
    
};