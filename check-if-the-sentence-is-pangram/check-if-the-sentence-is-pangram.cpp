class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        
        bitset<26> s;
        int i = 0;
        int sz = sentence.size();
        while( i < sz)
        {
            s |= (1 << sentence[i] - 'a');
            i++;
        }
        return s.all();
    }
};