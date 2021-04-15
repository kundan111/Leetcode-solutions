class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = -1;
        int sz = accounts.size();
        
        for(int i = 0; i < sz; i++)
        {
            vector <int> cur = accounts[i];
            int sum = 0;
            int j = 0;
            int temp_sz = cur.size();
            while(j < temp_sz)
            {
                sum = sum + cur[j];
                j++;
            }
            if(sum > res)
            {
                res = sum;
            }
        }
        
        return res;
    }
};