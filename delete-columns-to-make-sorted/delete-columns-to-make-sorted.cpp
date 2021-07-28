class Solution {
public:
    int minDeletionSize(vector<string>& strs,int res=0) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int wordSize = strs[0].size();
        int vecSize = strs.size();
        for(int i = 0; i < wordSize; i++)
        {
            for(int j = 1; j < vecSize; j++)
            {
                if(strs[j-1][i] > strs[j][i])
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};