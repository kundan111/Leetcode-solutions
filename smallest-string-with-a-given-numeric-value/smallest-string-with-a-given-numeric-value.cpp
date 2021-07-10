class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string res = string(n,'a');
        k = k-n;
        
        int i = res.size() - 1;
        while(k)
        {
            int tmp = min(k, 25);
            res[i] += (char)tmp;
            k -= tmp;
            --i;        
        }
        
        return res;
    }
};