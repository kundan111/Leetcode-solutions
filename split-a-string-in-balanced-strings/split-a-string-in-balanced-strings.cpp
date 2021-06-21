class Solution {
public:
    int res = 0;
    int balancedStringSplit(string s) {
        int sz = s.size();
        int counter = 0;
        for(int i = 0; i <sz; i++)
        {
            counter += (s[i] == 'L' ? 1 : -1);
            if(!counter)
                res++;
        }
        return res;
    }
};