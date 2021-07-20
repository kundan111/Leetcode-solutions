class Solution {
public:
    bool checkIfPangram(string sentence) {
        bitset<26> s;
        int i = 0;
        int sz = sentence.size();
        while( i < sz)
        {
            s[sentence[i] - 'a'] = 1;
            i++;
        }
        return s.all();
    }
};