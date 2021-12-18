class Solution {
public:
    int minSubArrayLen(int x, vector<int>& inp) {
        int sz = inp.size();
            if(sz == 0)
            {
                return 0;
            }

            int res = INT_MAX;
            int l = 0;
            int r = 0;
            int sum = 0;

            while(l <= r && r < sz)
            {
                
                sum += inp[r];
                
                if(sum >= x)
                {
                    res = min(res, r-l+1);
                }

                while(l < sz && sum >= x)
                {
                    res = min(res, r-l+1);
                    sum -= inp[l];
                    l++;
                }
                


                r++;
            }

            return res == INT_MAX ? 0 : res;
    }
};