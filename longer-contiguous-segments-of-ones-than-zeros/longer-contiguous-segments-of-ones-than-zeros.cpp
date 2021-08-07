class Solution {
public:
    bool checkZeroOnes(string s) {
        int sz = s.size();
        int i = 0;
        int max_1 = 0;
        int max_0 = 0;
        int j;
        while(i < sz)
        {
            if(s[i] == '1')
            {
                j = i;
                int cur_1 = 0;
                while(j < sz && s[j] == '1')
                {
                    cur_1++;
                    j++;
                }
                max_1 = max(max_1,cur_1);
            }else{
                j = i;
                int cur_0 = 0;
                while(j < sz && s[j] == '0')
                {
                    cur_0++;
                    j++;
                }
                max_0 = max(max_0,cur_0);
            }
            
            i = j;
        }
        
        // cout << max_1 << endl << max_0 << endl;
        
        return max_1 > max_0;
    }
};