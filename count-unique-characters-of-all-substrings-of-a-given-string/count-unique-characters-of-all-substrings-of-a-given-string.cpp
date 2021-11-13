class Solution {
public:
    int uniqueLetterString(string s) {
        int tracker[26][2];
        int sz = s.size();
        memset(tracker,-1, sizeof(int)*52);
        int res = 0;
        for(int i = 0; i < sz; i++)
        {
            int ind = s[i] - 'A';
            res += (i - tracker[ind][1])*(tracker[ind][1] - tracker[ind][0]);
            tracker[ind][0] = tracker[ind][1];
            tracker[ind][1] = i;
        }
        
        for(int i = 0; i < 26; i++)
        {
            res += (sz - tracker[i][1]) * (tracker[i][1] - tracker[i][0]);
        }
        return res;
    }
    
};