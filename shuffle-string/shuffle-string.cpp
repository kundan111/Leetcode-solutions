class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ret = s;
        int i = 0;
        int sz = s.size();
        while(i < sz)
        {
            ret[indices[i]] = s[i];
            i++;
        }
        
        return ret;
    }
};