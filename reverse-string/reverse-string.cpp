class Solution {
public:
    void reverseString(vector<char>& s) {
        int sz = s.size();
        int i = 0;
        while(i < sz/2)
        {
            swap(s[i],s[sz-i-1]);
            i++;
        }
        // return s;
    }
};