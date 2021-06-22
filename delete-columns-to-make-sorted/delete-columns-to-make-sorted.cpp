class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int sz = strs.size();
        int res = 0;
        int i = 1;
        int wordSize = strs[0].size();
        vector<int> temp(wordSize,0);
        while( i < sz)
        {
            string cur = strs[i];
            string prev = strs[i-1];
            int j = 0;
            
            while( j < wordSize)
            {
                if((prev[j] - 'a' > cur[j] -'a') && !temp[j])
                {
                    res++;
                    temp[j] = 1; 
                }
                j++;
            }
            i++;
        }
        
        return res;
    }
};